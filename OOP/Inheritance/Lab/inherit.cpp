#include "Child.h"
#include "Base.h"
#include <iostream> 


int main()
{
    Base b;
    b.printFunc();

    Child c;
    c.printFunc();

    return 0;
}
