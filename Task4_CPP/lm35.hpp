#ifndef LM35_HPP
#define LM35_HPP

#include <string>
class LMSensor
{

private:
    int fd;
    char buffer[10];
public:
    LMSensor(std::string UartPath);
    float readTemperature();
    ~LMSensor();
};

#endif // LM35_HPP