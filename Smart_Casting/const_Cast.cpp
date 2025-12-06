#include <iostream>

struct a
{
    int a1;
    int a2;
};

struct b
{
    /* data */
    int b1;
    int b2;
};

/* Won't Work With Global Vars As it is in .ROData */
// const int x = 150;

int main()
{   
    const int x = 150;

    // int *ptr = (int *)&x;
    // *ptr = 200;

    /* Won't Work */
    // int *ptr = &x;
    // *ptr = 100;

    // int *ptr = const_cast<int *>(&x);
    int *ptr = nullptr;
    *ptr = 100;

    std::cout << x <<std::endl;
}