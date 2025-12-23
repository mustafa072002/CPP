#ifndef SEVENSEG_HEADER_HPP
#define SEVENSEG_HEADER_HPP

#include <OStream.hpp>
#include <IStream.hpp>
#include <gpio.hpp>

class SevenSeg final: public IStream, public OStream
{
private:
    MCAL::GPIO::GPIO a;
    MCAL::GPIO::GPIO b;
    MCAL::GPIO::GPIO c;
    MCAL::GPIO::GPIO d;
    MCAL::GPIO::GPIO e;
    MCAL::GPIO::GPIO f;
    MCAL::GPIO::GPIO g;
public:
    SevenSeg();
    virtual void WriteDigit(int digit) override;
    ~SevenSeg();
};

#endif