#ifndef ISTREAM_HEADER_HPP
#define ISTREAM_HEADER_HPP

#include <Stream.hpp>

class IStream : virtual public Stream
{
private:
    /*Private Atrributes */
public:
    IStream();
    int readDigit(void);
    virtual ~IStream();
};

#endif /* ISTREAM_HEADER_HPP */