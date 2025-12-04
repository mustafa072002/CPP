#ifndef GPIO_MCAL_HEADER
#define GPIO_MCAL_HEADER

#include <memory>
#include <string>
#include <stdint.h>
#include <iostream>

namespace MCAL::GPIO
{
    typedef enum
    {
        GPIO_OK
    } GPIO_enu_ERR_t;

    typedef enum
    {
        DIGITAL_INPUT,
        DIGITAL_OUTPUT
    } GPIO_pinMode_t;

    typedef enum
    {
        LOGIC_LOW,
        LOGIC_HIGH
    } GPIO_pinLevel_t;

    class GPIO
    {
    private:
        std::string path_ = "/sys/class/gpio";
        uint8_t pinNum_ = 0;
        std::unique_ptr<int> value_Fd_ = nullptr;
        std::unique_ptr<int> Dir_Fd_ = nullptr;

    public:
        // Delete Default Constructor User Must Pass Gpio Path
        GPIO() = delete;
        // Parameterized Constructors
        GPIO(uint8_t pinNum);

        GPIO(uint8_t pinNum , GPIO_pinMode_t pinMode);

        GPIO(uint8_t pinNum , GPIO_pinMode_t pinMode , GPIO_pinLevel_t initlevel);
        /* Apply Rule Of 5 */

        // Copy Constructor
        GPIO(const GPIO &obj);

        // Move Constructor
        GPIO(GPIO &&obj);

        // Copy Assignment Operator
        GPIO& operator=(const GPIO &obj);

        // Move Assignment Operator
        GPIO& operator=(GPIO &&obj);

        // Destructor
        ~GPIO();

        GPIO_enu_ERR_t GPIO_Init(GPIO_pinMode_t pinMode);

        GPIO_enu_ERR_t GPIO_Write(GPIO_pinLevel_t level);

        GPIO_enu_ERR_t GPIO_Read(GPIO_pinLevel_t &level);
    };
}

#endif /* GPIO_MCAL_HEADER */