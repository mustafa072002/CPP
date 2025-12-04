#include <initializer_list>
#include <iostream>
#include <utility>

std::pair<int,char> func(std::initializer_list <char> x){
    return {15,25};
}

void fun(int *ptr){
    return;
}
std::initializer_list<int> func2(){
    return {10,20,30,40};
}

int main(){
    8++;
    fun(5);

}
