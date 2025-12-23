#ifndef CHILD_H
#define CHILD_H

#include "Base.h"

class Child : public Base
{
private:
    int chdY;
public:
    Child();
    void printFunc();
};

#endif // CHILD_H