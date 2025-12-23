#include <SevenSeg.hpp>

SevenSeg::SevenSeg()
    : a(14, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      b(15, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      c(18, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      d(23, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      e(24, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      f(25, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH),
      g(8, MCAL::GPIO::DIGITAL_OUTPUT, MCAL::GPIO::LOGIC_HIGH)
{
    std::cout << "SevenSeg Constructor\n";
}

SevenSeg::~SevenSeg()
{
    std::cout << "SevenSeg Destructor\n";
}


/* Helper: turn all segments off */
static void turnOffAll(
    MCAL::GPIO::GPIO& a,
    MCAL::GPIO::GPIO& b,
    MCAL::GPIO::GPIO& c,
    MCAL::GPIO::GPIO& d,
    MCAL::GPIO::GPIO& e,
    MCAL::GPIO::GPIO& f,
    MCAL::GPIO::GPIO& g)
{
    a.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    b.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    c.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    d.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    e.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    f.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
    g.GPIO_Write(MCAL::GPIO::LOGIC_HIGH);
}

void SevenSeg::WriteDigit(int digit)
{
    if (digit < 0 || digit > 9)
    {
        std::cout << "SevenSeg: Invalid digit\n";
        return;
    }

    /* Clear previous state */
    turnOffAll(a, b, c, d, e, f, g);

    switch (digit)
    {
        case 0:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            e.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 1:
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 2:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            e.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 3:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 4:
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 5:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 6:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            e.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 7:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 8:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            e.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;

        case 9:
            a.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            b.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            c.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            d.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            f.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            g.GPIO_Write(MCAL::GPIO::LOGIC_LOW);
            break;
    }
}