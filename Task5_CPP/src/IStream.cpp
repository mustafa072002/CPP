#include <IStream.hpp>
#include <iostream>

IStream::IStream()
{
    std::cout << "IStream Constructor\n";
}

IStream::~IStream()
{
    std::cout << "IStream Destructor\n";
}

int IStream::readDigit(void)
{
    int num = -1;
    while (true)
    {
        std::cout << "Enter Number 0~9\n";
        std::cin >> num;
        if (num <= 9 && num >= 0)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Number Retry ..\n";
        }
    }
    return num;
}

