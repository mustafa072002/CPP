#include "fun1.h"
#include "fun2.h"
#include "stdio.h"

using namespace add_1 ;
using namespace add_2;
int main(){
	int a = 5 ;
	int b = 3 ;
	int x = add(a,b);
	int y = add(a,b);
	printf("First Add :  %d and The Second Add : %d \n" , x , y); 
}
