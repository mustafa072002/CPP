#include <iostream>
#include <memory>
#include <Stream.hpp>
#include <SevenSeg.hpp>
#include <IOStream.hpp>
int main()
{
    SevenSeg svnSeg;
    IOStream IOStrm;

    Stream& segRef = svnSeg;
    Stream& ioRef = IOStrm;

    int digit = segRef.readDigit();
    segRef.WriteDigit(digit);

    digit =ioRef.readDigit();
    ioRef.WriteDigit(digit);
    
}