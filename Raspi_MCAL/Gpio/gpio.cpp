#include "gpio.hpp"
#include <fcntl.h>
#include <unistd.h>

namespace MCAL::GPIO
{
    GPIO::GPIO(uint8_t pinNum)
    {
        this->pinNum_ = pinNum;
        std::cout << "GPIO(uint8_t pinNum) Param Construct\n";
        // open file descriptor on export -> write pinNum -> close
        std::string expPath = path_ + "/export";
        int exportFd = open(expPath.c_str(), O_WRONLY);

        std::string pinStr = std::to_string(pinNum + 512);
        write(exportFd, pinStr.c_str(), pinStr.length());
        close(exportFd);

        // Initialize value_Fd_ and Dir_Fd_
        std::string valuePath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/value";
        value_Fd_.reset(new int(open(valuePath.c_str(), O_RDWR)));

        std::string dirPath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/direction";
        Dir_Fd_.reset(new int(open(dirPath.c_str(), O_RDWR)));
    }

    GPIO::GPIO(uint8_t pinNum, GPIO_pinMode_t pinMode)
    {
        this->pinNum_ = pinNum;
        std::cout << "GPIO(uint8_t pinNum, GPIO_pinMode_t pinMode) Param Construct\n";
        // open file descriptor on export -> write pinNum -> close
        std::string expPath = path_ + "/export";
        int exportFd = open(expPath.c_str(), O_WRONLY);

        std::string pinStr = std::to_string(pinNum + 512);
        write(exportFd, pinStr.c_str(), pinStr.length());
        close(exportFd);

        // Initialize value_Fd_ and Dir_Fd_
        std::string valuePath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/value";
        value_Fd_.reset(new int(open(valuePath.c_str(), O_RDWR)));

        std::string dirPath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/direction";
        Dir_Fd_.reset(new int(open(dirPath.c_str(), O_RDWR)));

        std::string modeStr;
        switch (pinMode)
        {
        case DIGITAL_INPUT:
            modeStr = "in";
            break;
        case DIGITAL_OUTPUT:
            modeStr = "out";
            break;
        default:
            break;
        }
        write(*Dir_Fd_, modeStr.c_str(), modeStr.length());
    }

    GPIO::GPIO(uint8_t pinNum, GPIO_pinMode_t pinMode, GPIO_pinLevel_t initlevel)
    {
        this->pinNum_ = pinNum;
        std::cout << "GPIO(uint8_t pinNum, GPIO_pinMode_t pinMode, GPIO_pinLevel_t initlevel) Param Construct\n";
        // open file descriptor on export -> write pinNum -> close
        std::string expPath = path_ + "/export";
        int exportFd = open(expPath.c_str(), O_WRONLY);

        std::string pinStr = std::to_string(pinNum + 512);
        write(exportFd, pinStr.c_str(), pinStr.length());
        close(exportFd);

        // Initialize value_Fd_ and Dir_Fd_
        std::string valuePath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/value";
        std::cout << "Value Path: " << valuePath << "\n";
        value_Fd_.reset(new int(open(valuePath.c_str(), O_RDWR)));

        std::string dirPath = path_ + "/gpio" + std::to_string(pinNum + 512) + "/direction";
        std::cout << "Dir Path: " << dirPath << "\n";
        Dir_Fd_.reset(new int(open(dirPath.c_str(), O_RDWR)));
        std::string modeStr;
        std::string levelStr;
        switch (pinMode)    
        {
        case DIGITAL_INPUT:
            modeStr = "in";
            break;
        case DIGITAL_OUTPUT:
            modeStr = "out";
            break;
        default:
            break;
        }

        switch (initlevel)
        {
        case LOGIC_LOW:
            levelStr = "0";
            break;
        case LOGIC_HIGH:
            levelStr = "1";
            break;
        default:
            break;
        }
        std::cout << "Dir " <<*Dir_Fd_ << "  Value" << *value_Fd_ << "\n";
        write(*Dir_Fd_, modeStr.c_str(), modeStr.length());
        write(*value_Fd_, levelStr.c_str(), levelStr.length());
    }

    GPIO_enu_ERR_t GPIO::GPIO_Init(GPIO_pinMode_t pinMode)
    {
        std::cout << "GPIO_Init(GPIO_pinMode_t pinMode) Method\n";
        GPIO_enu_ERR_t err = GPIO_OK;
        std::string modeStr;
        switch (pinMode)
        {
        case DIGITAL_INPUT:
            modeStr = "in";
            break;
        case DIGITAL_OUTPUT:
            modeStr = "out";
            break;
        default:
            break;
        }
        write(*Dir_Fd_, modeStr.c_str(), modeStr.length());
        return err;
    }

    GPIO_enu_ERR_t GPIO::GPIO_Write(GPIO_pinLevel_t level)
    {
        std::cout << "GPIO_Write(GPIO_pinLevel_t level) Method\n";
        GPIO_enu_ERR_t err = GPIO_OK;
        std::string levelStr;
        switch (level)
        {
        case LOGIC_LOW:
            levelStr = "0";
            std::cout << "Writing LOW level\n";
            break;
        case LOGIC_HIGH:
            levelStr = "1";
            std::cout << "Writing HIGH level\n";
            break;
        default:
            break;
        }
        write(*value_Fd_, levelStr.c_str(), levelStr.length());
        return err;
    }

    GPIO_enu_ERR_t GPIO::GPIO_Read(GPIO_pinLevel_t &level)
    {
        std::cout << "GPIO_Read(GPIO_pinLevel_t level) Method\n";
        GPIO_enu_ERR_t err = GPIO_OK;
        char levelChr;
        lseek(*value_Fd_, 0, SEEK_SET);
        read(*value_Fd_, &levelChr, 1);
        if (levelChr == '0')
        {
            level = LOGIC_LOW;
            std::cout << "Level is LOW\n";
        }
        else if (levelChr == '1')
        {
            level = LOGIC_HIGH;
            std::cout << "Level is HIGH\n";
        }
        return err;
    }

    GPIO::~GPIO()
    {
        std::cout << "~GPIO() Destructor\n";
        // close file descriptors
        if (value_Fd_ && *value_Fd_ != -1)
        {   
            write(*value_Fd_, "0", 1); // Set to LOW before closing
            close(*value_Fd_);
        }
        if (Dir_Fd_ && *Dir_Fd_ != -1)
        {
            write(*Dir_Fd_, "in", 2); // Set direction to input before closing
            close(*Dir_Fd_);
        }

        // unexport the pin
        std::string unexpPath = path_ + "/unexport";
        int unexportFd = open(unexpPath.c_str(), O_WRONLY);

        // Extract pin number from value_Fd_ path
        std::string pinStr = std::to_string(pinNum_ + 512);
        write(unexportFd, pinStr.c_str(), pinStr.length());
        close(unexportFd);
    }

    GPIO& GPIO::operator=(const GPIO &obj){
        
    }
}

// Implementations of GpioPin class methods would go here
