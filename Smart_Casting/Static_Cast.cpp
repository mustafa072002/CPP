#include <iostream>

struct a{
    int a1;
    int a2;
};

struct b
{
    /* data */
    int b1;
    int b2;
};


int main()
{
    int x = 10;
    float y = static_cast<float>(x);

    /* Won't Work As Different Classes */
    // a a_var = {10 , 20};
    // b b_var = static_cast<b> a_var;

    /* Won't work As ptr to primType */
    // int *ptr = &x;
    // int y = static_cast<int>(ptr);

    std::cout << y <<std::endl;
}