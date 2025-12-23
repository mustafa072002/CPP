#include <iostream>
#include <string>

class LCD
{
public:
    std::string name;

public:
    LCD() = default;
    LCD(const std::string &name) : name{name}
    {

        std::cout << "From LCD Parent" << std::endl;
    };
    void DisplayString() const
    {
        std::cout << "Parent Func" << std::endl;
        std::cout << name.c_str() << std::endl;
    }
};

/* By default Private */
class LCD_4 : public LCD
{
public:
    /* Call parent constructor, not parent member */

    LCD_4(const std::string &name) : LCD(name)
    {
        std::cout << "From LCD_4 Child" << std::endl;
    };

    void DisplayString() const
    {

        std::cout << "Child Func" << std::endl;
        std::cout << name.c_str() << std::endl;
    }
};

int main()
{
    LCD_4 obj{"Hello"};
    LCD *p =nullptr;

    /* Compiler Choose What function to call depend on the type */
    obj.DisplayString();
    p->DisplayString();
}