#include "lm35.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

LMSensor::LMSensor(std::string UartPath)
{
    fd = open(UartPath.c_str(), O_RDONLY);
}

float LMSensor::readTemperature()
{
    char ch;
    int index = 0;

    // Read characters until newline
    while (true)
    {
        ssize_t bytesRead = read(fd, &ch, 1);

        if (bytesRead <= 0)
        {
            // Read error or no data
            return -1.0f;
        }

        if (ch == '\n')
        {
            break;
        }

        if (index < static_cast<int>(sizeof(buffer)) - 1)
        {
            buffer[index++] = ch;
        }
        else
        {
            // Buffer full, discard line
            return -1.0f;
        }
    }

    // Handle empty line
    if (index == 0)
    {
        return -1.0f;
    }

    // Remove carriage return if present (Arduino sends \r\n)
    if (buffer[index - 1] == '\r')
    {
        index--;
    }

    buffer[index] = '\0';  // Proper null termination


    // Validate numeric start
    if (!(isdigit(buffer[0]) || buffer[0] == '-' || buffer[0] == '+'))
    {
        return -1.0f;
    }

    float temperature;

    try
    {
        temperature = std::stof(buffer);
    }
    catch (const std::exception&)
    {
        return -1.0f;
    }

    return temperature;
}


LMSensor::~LMSensor()
{
    // Destructor implementation (if needed)
    close(fd);
}
