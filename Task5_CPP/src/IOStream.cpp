#include <IOStream.hpp>
#include <iostream>

IOStream::IOStream()
{
    std::cout << "IOSTREAM Constructor\n";
}

IOStream::~IOStream()
{
    std::cout << "IOSTREAM Destructor\n";
}

void IOStream::WriteDigit(int digit)
{
    std::cout << "Digit " << digit << std::endl;
}