#ifndef STREAM_HEADER_HPP
#define STREAM_HEADER_HPP

class Stream
{
private:
    /* data */
public:
    Stream();
    virtual int readDigit(void) = 0; 
    virtual void WriteDigit(int digit) = 0;
    virtual ~Stream();
};


#endif