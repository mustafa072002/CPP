#ifndef OSTREAM_HEADER_HPP
#define OSTREAM_HEADER_HPP
#include <Stream.hpp>

class OStream : virtual public Stream
{
private:
    /* data */
public:
    OStream();
    virtual void WriteDigit(int digit) = 0;
    virtual ~OStream();
};


#endif