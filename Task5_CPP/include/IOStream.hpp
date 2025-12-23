#ifndef IOSTREAM_HEADER_HPP
#define IOSTREAM_HEADER_HPP

#include <IStream.hpp>
#include <OStream.hpp>
#include <iostream>

class IOStream final : public IStream, public OStream
{
private:

public:
    IOStream();
    void WriteDigit(int digit);
    ~IOStream();
};

#endif