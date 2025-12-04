
#include "gpio.h"

NAMESPACE__S(MCAL::GPIO)

GPIO_Error_t GPIO_initPin(void *GPIO_Port, uint8_t pin, uint8_t modeMask)
{
    GPIO_Error_t err = GPIO_enu_OK;
    GPIO_t *portAdd = (GPIO_t *)GPIO_Port;
    if (NULL == portAdd || ((GPIOA != portAdd) && (GPIOB != portAdd) && (GPIOC != portAdd) && (GPIOD != portAdd) && (GPIOE != portAdd) && (GPIOH != portAdd)))
    {
        err = GPIO_enu_INVALID_PORT;
    }
    else if (RIGHT_PIN != (pin & GPIO_PIN_ERR_MASK))
    {
        err = GPIO_enu_INVALID_PIN;
    }
    else
    {
        uint8_t mode = (modeMask & BITS2_MASK);
        portAdd->MODER.REG = (portAdd->MODER.REG & ~(BITS2_MASK << (pin * 2))) | (mode << (pin * 2));

        uint8_t res = (modeMask >> PUPD_BIT_POS) & BITS2_MASK;
        portAdd->PUPDR.REG = (portAdd->PUPDR.REG & ~(BITS2_MASK << (pin * 2))) | (res << (pin * 2));

        uint8_t ppod = (modeMask >> PPOD_BIT_POS) & BIT1_MASK;
        portAdd->OTYPER.REG = (portAdd->OTYPER.REG & ~(BIT1_MASK << pin)) | (ppod << pin);
    }
    return err;
}

GPIO_Error_t GPIO_writePin(void *GPIO_Port, uint8_t pin, uint8_t value)
{
    GPIO_Error_t err = GPIO_enu_OK;
    GPIO_t *portAdd = (GPIO_t *)GPIO_Port;
    if (NULL == portAdd || ((GPIOA != portAdd) && (GPIOB != portAdd) && (GPIOC != portAdd) && (GPIOD != portAdd) && (GPIOE != portAdd) && (GPIOH != portAdd)))
    {
        err = GPIO_enu_INVALID_PORT;
    }
    else if (RIGHT_PIN != (pin & GPIO_PIN_ERR_MASK))
    {
        err = GPIO_enu_INVALID_PIN;
    }
    else
    {
        if (value)
        {
            portAdd->BSRR.REG = (1 << pin);
        }
        else
        {
            portAdd->BSRR.REG = (1 << (pin + 16));
        }
    }
    return err;
}

// GPIO_Error_t GPIO_togglePin(void *GPIO_Port, uint8_t pin)
// {
// }

GPIO_Error_t GPIO_readPin(void *GPIO_Port, uint8_t pin, uint8_t *value)
{
    GPIO_Error_t err = GPIO_enu_OK;
    GPIO_t *portAdd = (GPIO_t *)GPIO_Port;
    if (NULL == portAdd || ((GPIOA != portAdd) && (GPIOB != portAdd) && (GPIOC != portAdd) && (GPIOD != portAdd) && (GPIOE != portAdd) && (GPIOH != portAdd)))
    {
        err = GPIO_enu_INVALID_PORT;
    }
    else if (RIGHT_PIN != (pin & GPIO_PIN_ERR_MASK))
    {
        err = GPIO_enu_INVALID_PIN;
    }
    else
    {
        *value = (portAdd->IDR.REG >> pin) & 0x01;
    }
    return err;
}

NAMESPACE__E
