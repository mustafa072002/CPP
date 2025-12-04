#include "gpio.hpp"
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <iostream>

// Flag to control the loop
volatile sig_atomic_t running = 1;

// Signal handler
void signalHandler(int signum)
{
    std::cout << "\nCaught signal " << signum << ", exiting...\n";
    running = 0;
}

int main()
{
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);
    
    MCAL::GPIO::GPIO gpio1(23);
    gpio1.GPIO_Init(MCAL::GPIO::DIGITAL_OUTPUT);
    gpio1.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);

    MCAL::GPIO::GPIO gpio2(24, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_LOW);

    while (running)
    {
        gpio1.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
        gpio2.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
        
        // Use shorter sleeps to respond faster to signal
        for (int i = 0; i < 30 && running; i++)
            usleep(100000);  // 100ms * 30 = 3s
        
        if (!running) break;
        
        gpio1.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
        gpio2.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
        
        for (int i = 0; i < 30 && running; i++)
            usleep(100000);
    }

    std::cout << "Cleaning up GPIOs...\n";
    // Destructors will be called automatically here
    return 0;
}