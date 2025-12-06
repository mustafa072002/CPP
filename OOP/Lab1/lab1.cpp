#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <iostream>

class FileActions
{
private:
    std::string path;
    int *fd;
    std::vector<std::pair<std::string, int>> actions_;

public:
    FileActions()
    {
        path = "/sys/class/leds/input3::capslock/brightness";
        fd = new int(); // Allocate first!
        *fd = open(path.data(), O_RDWR);
        if (*fd < 0)
        {
            std::cerr << "Failed to open: " << path << std::endl;
        }
    }

    FileActions(std::string _path)
    {
        path = _path;
        fd = new int();
        *fd = open(path.data(), O_RDWR);
        if (*fd < 0)
        {
            std::cerr << "Failed to open: " << path << std::endl;
        }
    }

    FileActions(const FileActions &other)
    {
        path = other.path;
        actions_ = other.actions_;
        fd = new int();
        *fd = open(path.data(), O_RDWR); // Open new fd, don't copy old one
    }

    FileActions(FileActions &&temp) noexcept
    {
        path = std::move(temp.path);
        actions_ = std::move(temp.actions_);
        fd = temp.fd;
        temp.fd = nullptr; // Prevent double close
    }

    FileActions &operator=(const FileActions &other)
    {
        if (this != &other)
        {
            if (fd)
            {
                close(*fd);
                delete fd;
            }
            path = other.path;
            actions_ = other.actions_;
            fd = new int();
            *fd = open(path.data(), O_RDWR);
        }
        return *this;
    }

    FileActions &operator=(FileActions &&temp) noexcept
    {
        if (this != &temp)
        {
            if (fd)
            {
                close(*fd);
                delete fd;
            }
            path = std::move(temp.path);
            actions_ = std::move(temp.actions_);
            fd = temp.fd;
            temp.fd = nullptr;
        }
        return *this;
    }

    void registerActions(std::initializer_list<std::pair<std::string, int>> pair)
    {
        for (const auto &action : pair)
        {
            actions_.push_back(action);
        }
    }

    void executeActions(void)
    {
        for (size_t i = 0; i < actions_.size(); i++)
        {
            if (actions_[i].first == "write")
            {
                std::string value = std::to_string(actions_[i].second);
                write(*fd, value.c_str(), value.size());
            }
            else if (actions_[i].first == "read")
            {
                char buffer[256];
                lseek(*fd, 0, SEEK_SET);
                ssize_t bytesRead = read(*fd, buffer, sizeof(buffer) - 1);
                if (bytesRead > 0)
                {
                    buffer[bytesRead] = '\0';
                    std::cout << "Read: " << buffer << std::endl;
                }
            }
            else if (actions_[i].first == "sleep")
            {
                usleep(actions_[i].second * 1000);
            }
        }
    }

    ~FileActions()
    {
        if (fd)
        {
            close(*fd);
            delete fd;
        }
    }
};

int main() noexcept
{
    FileActions led("/sys/class/leds/input3::capslock/brightness");

    led.registerActions({
        {"write", 1},
        {"sleep", 500},
        {"write", 0},
        {"sleep", 500},
        {"write", 1},
        {"sleep", 500},
        {"write", 0},
        {"sleep", 500},
        {"write", 1},
        {"sleep", 500},
        {"write", 0}});

    led.executeActions();

    return 0;
}