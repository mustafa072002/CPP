#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>

class FileActions
{
private:
    std::string path;
    int *fd;
    int *&fdRef = fd;
    std::vector<std::pair<std::string, int>> actions_;

public:
    FileActions()
    {
        path = "/sys/class/leds/input3::capslock/brightness";
        *fd = open(path.data(), O_RDWR);
    }

    FileActions(std::string _path)
    {
        path = _path;
        fd = new int();
        *fd = open(path.data(), O_RDWR);
    }

    FileActions(const FileActions &other)
    {
        fd = new int();
        *fd = *other.fd;
    }

    FileActions(FileActions && temp) = default;

    void registerActions(std::initializer_list<std::pair<std::string, int>> pair)
    {
        for (int i = 0; i < pair.size(); i++)
        {
            actions_.push_back(*(pair.begin() + i));
        }
    }

    void executeActions(void)
    {
        for (int i = 0; i < actions_.size(); i++)
        {
            if (actions_[i].first == "write")
            {
            }
        }
    }
    ~FileActions()
    {
        close(*fd);
    }
};

int main() noexcept
{   
    int *ptr = NULL;
    *ptr;
    FileActions obj("/sys/class/leds/input3::capslock/brightness");
    // obj.capsLockOn();
}