#include <memory>
#include <iostream>

class A
{
private:
    int x = 0;
public:

    void incX(){
        x++;
    }
    void printx() const
    {
        std::cout << x ;
    }
};


int main()
{
    const A var;
    var.printx();
}