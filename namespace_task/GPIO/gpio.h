
#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
#define NAMESPACE__S(x) namespace x {
#define NAMESPACE__E }
#else
#define NAMESPACE__S(x)
#define NAMESPACE__E

#endif


NAMESPACE__S(MCAL::GPIO)
#include "inttypes.h"
/* ================ MASKS ================= */
/* First 2 Bits For Mode - > 00 --> Input
                             01 -- > Output
                             10 -- > ALtFunc
                             11 -- > Analog

    Second 2 Bits For Pull Or Pull Down
                           - > 00 No PUR / No PDR
                               01 PUR
                               10 PDR
    
    Third Bit for Push Pull or Open Drain

*/  
#define BITS2_MASK 0x03
#define BIT1_MASK 0x01


#define GPIO_MODE_IN_NPUD   0b0000
#define GPIO_MODE_IN_PU    0b0100
#define GPIO_MODE_IN_PD     0b1000

#define GPIO_MODE_OUT_NPUD_PP   0b00001
#define GPIO_MODE_OUT_PU_PP     0b00101
#define GPIO_MODE_OUT_PD_PP     0b01001
#define PUPD_BIT_POS 2

#define GPIO_MODE_OUT_NPUD_OD   0b10001
#define GPIO_MODE_OUT_PU_OD     0b10101
#define GPIO_MODE_OUT_OD_PD     0b11001
#define PPOD_BIT_POS 4

#define GPIO_MODE_ALTFN     0b10
#define GPIO_MODE_ANALOG    0b11

#ifndef NULL
#define NULL ((void *)0)
#endif

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#define RIGHT_PIN 0

#define LOGIC_HIGH 1
#define LOGIC_LOW 0

#define GPIO_PIN_ERR_MASK 0xF0
#define GPIOA ((void *)0x40020000)
#define GPIOB ((void *)0x40020400)
#define GPIOC ((void *)0x40020800)
#define GPIOD ((void *)0x40020C00)
#define GPIOE ((void *)0x40021000)
#define GPIOH ((void *)0x40021C00)

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t MODER0 : 2;
        volatile uint32_t MODER1 : 2;
        volatile uint32_t MODER2 : 2;
        volatile uint32_t MODER3 : 2;
        volatile uint32_t MODER4 : 2;
        volatile uint32_t MODER5 : 2;
        volatile uint32_t MODER6 : 2;
        volatile uint32_t MODER7 : 2;
        volatile uint32_t MODER8 : 2;
        volatile uint32_t MODER9 : 2;
        volatile uint32_t MODER10 : 2;
        volatile uint32_t MODER11 : 2;
        volatile uint32_t MODER12 : 2;
        volatile uint32_t MODER13 : 2;
        volatile uint32_t MODER14 : 2;
        volatile uint32_t MODER15 : 2;
    } BIT;
} GPIO_MODER_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t OT0 : 1;
        volatile uint32_t OT1 : 1;
        volatile uint32_t OT2 : 1;
        volatile uint32_t OT3 : 1;
        volatile uint32_t OT4 : 1;
        volatile uint32_t OT5 : 1;
        volatile uint32_t OT6 : 1;
        volatile uint32_t OT7 : 1;
        volatile uint32_t OT8 : 1;
        volatile uint32_t OT9 : 1;
        volatile uint32_t OT10 : 1;
        volatile uint32_t OT11 : 1;
        volatile uint32_t OT12 : 1;
        volatile uint32_t OT13 : 1;
        volatile uint32_t OT14 : 1;
        volatile uint32_t OT15 : 1;
    } BIT;
} GPIO_OTYPER_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t PUPD0 : 2;
        volatile uint32_t PUPD1 : 2;
        volatile uint32_t PUPD2 : 2;
        volatile uint32_t PUPD3 : 2;
        volatile uint32_t PUPD4 : 2;
        volatile uint32_t PUPD5 : 2;
        volatile uint32_t PUPD6 : 2;
        volatile uint32_t PUPD7 : 2;
        volatile uint32_t PUPD8 : 2;
        volatile uint32_t PUPD9 : 2;
        volatile uint32_t PUPD10 : 2;
        volatile uint32_t PUPD11 : 2;
        volatile uint32_t PUPD12 : 2;
        volatile uint32_t PUPD13 : 2;
        volatile uint32_t PUPD14 : 2;
        volatile uint32_t PUPD15 : 2;
    } BIT;
} GPIO_PUPDR_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t IDR0 : 1;
        volatile uint32_t IDR1 : 1;
        volatile uint32_t IDR2 : 1;
        volatile uint32_t IDR3 : 1;
        volatile uint32_t IDR4 : 1;
        volatile uint32_t IDR5 : 1;
        volatile uint32_t IDR6 : 1;
        volatile uint32_t IDR7 : 1;
        volatile uint32_t IDR8 : 1;
        volatile uint32_t IDR9 : 1;
        volatile uint32_t IDR10 : 1;
        volatile uint32_t IDR11 : 1;
        volatile uint32_t IDR12 : 1;
        volatile uint32_t IDR13 : 1;
        volatile uint32_t IDR14 : 1;
        volatile uint32_t IDR15 : 1;
    } BIT;
} GPIO_IDR_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t ODR0 : 1;
        volatile uint32_t ODR1 : 1;
        volatile uint32_t ODR2 : 1;
        volatile uint32_t ODR3 : 1;
        volatile uint32_t ODR4 : 1;
        volatile uint32_t ODR5 : 1;
        volatile uint32_t ODR6 : 1;
        volatile uint32_t ODR7 : 1;
        volatile uint32_t ODR8 : 1;
        volatile uint32_t ODR9 : 1;
        volatile uint32_t ODR10 : 1;
        volatile uint32_t ODR11 : 1;
        volatile uint32_t ODR12 : 1;
        volatile uint32_t ODR13 : 1;
        volatile uint32_t ODR14 : 1;
        volatile uint32_t ODR15 : 1;
    } BIT;
} GPIO_ODR_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t BS0 : 1;
        volatile uint32_t BS1 : 1;
        volatile uint32_t BS2 : 1;
        volatile uint32_t BS3 : 1;
        volatile uint32_t BS4 : 1;
        volatile uint32_t BS5 : 1;
        volatile uint32_t BS6 : 1;
        volatile uint32_t BS7 : 1;
        volatile uint32_t BS8 : 1;
        volatile uint32_t BS9 : 1;
        volatile uint32_t BS10 : 1;
        volatile uint32_t BS11 : 1;
        volatile uint32_t BS12 : 1;
        volatile uint32_t BS13 : 1;
        volatile uint32_t BS14 : 1;
        volatile uint32_t BS15 : 1;

        volatile uint32_t BR0 : 1;
        volatile uint32_t BR1 : 1;
        volatile uint32_t BR2 : 1;
        volatile uint32_t BR3 : 1;
        volatile uint32_t BR4 : 1;
        volatile uint32_t BR5 : 1;
        volatile uint32_t BR6 : 1;
        volatile uint32_t BR7 : 1;
        volatile uint32_t BR8 : 1;
        volatile uint32_t BR9 : 1;
        volatile uint32_t BR10 : 1;
        volatile uint32_t BR11 : 1;
        volatile uint32_t BR12 : 1;
        volatile uint32_t BR13 : 1;
        volatile uint32_t BR14 : 1;
        volatile uint32_t BR15 : 1;
    } BIT;
} GPIO_BSRR_t;

typedef union
{
    volatile uint32_t REG;
    struct
    {
        volatile uint32_t AFRL0 : 4;
        volatile uint32_t AFRL1 : 4;
        volatile uint32_t AFRL2 : 4;
        volatile uint32_t AFRL3 : 4;
        volatile uint32_t AFRL4 : 4;
        volatile uint32_t AFRL5 : 4;
        volatile uint32_t AFRL6 : 4;
        volatile uint32_t AFRL7 : 4;
    } BIT;
} GPIO_AFRL_t;

typedef struct
{
    volatile GPIO_MODER_t MODER;
    volatile GPIO_OTYPER_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile GPIO_PUPDR_t PUPDR;
    volatile GPIO_IDR_t IDR;
    volatile GPIO_ODR_t ODR;
    volatile GPIO_BSRR_t BSRR;
    volatile uint32_t LCKR;
    volatile GPIO_AFRL_t AFR[2];
} GPIO_t;

typedef enum
{
    GPIO_enu_OK = 0,
    GPIO_enu_INVALID_PORT,
    GPIO_enu_INVALID_PIN,
    GPIO_enu_INVALID_MODE,
    GPIO_enu_INVALID_OTYPE,
    GPIO_enu_INVALID_OSPEED,
    GPIO_enu_INVALID_PUPD

} GPIO_Error_t;

GPIO_Error_t GPIO_initPin(void *GPIO_Port, uint8_t pin, uint8_t modeMask);
GPIO_Error_t GPIO_writePin(void *GPIO_Port, uint8_t pin, uint8_t value);
GPIO_Error_t GPIO_togglePin(void *GPIO_Port, uint8_t pin);
GPIO_Error_t GPIO_readPin(void *GPIO_Port, uint8_t pin, uint8_t *value);

NAMESPACE__E

#endif