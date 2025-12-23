#include "lm35.hpp"
#include <iostream>
#include <memory>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>

void DisplayTemperature(const std::shared_ptr<float> &temperature)
{
    std::cout << "Temperature: " << *temperature << " °C" << std::endl;
}
int fd = -1;
void LogTemperature(const std::shared_ptr<float> &temperature)
{
    if (fd != -1)
    {
        std::string logEntry = "Temperature: " + std::to_string(*temperature) + " °C\n";
        write(fd, logEntry.c_str(), logEntry.size());
    }
}

int main()
{
    fd = open("LogFile.txt", O_CREAT | O_WRONLY);
    std::unique_ptr<LMSensor> tempSensor = std::make_unique<LMSensor>("/dev/serial0");
    float temperatureData = tempSensor->readTemperature();
    std::shared_ptr<float> temperaturePtr = std::make_shared<float>(temperatureData);

    for (int i = 0; i < 1000; i++)
    {
        *temperaturePtr = tempSensor->readTemperature();
        DisplayTemperature(temperaturePtr);
        LogTemperature(temperaturePtr);
        usleep(10000); // 0.01 second delay
    }
    if (fd != -1)
    {
        close(fd);
    }
    return 0;
}