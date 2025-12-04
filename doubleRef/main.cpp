#include <iostream>

struct mainStruct{

    int a;
    int b;
};


mainStruct &&func(int a ,int val)
{
    
    mainStruct &&var = {10,20};
    if(a==1){
        var.b = val;
    }
    return (mainStruct&&)var;
}

int main(){
    mainStruct vari = func(1,1555);
    mainStruct vari2 = func(0,2445);

    std::cout << vari2.b <<std::endl;
}