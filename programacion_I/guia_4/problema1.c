#include "stdlib.h"
#include "stdio.h"
int main(){
int num1,num2,num3;
int *ptr1,*ptr2,*ptr3, **ptrptr1, **ptrptr2;
num1 = 10;
num2 = 20;
num3 = 30;
ptr1 = &num1;
ptr2 = &num2;
ptr3 = &num3;
ptrptr1 = &ptr1;
ptrptr2 = &ptr2;
*ptr1 = 50;
*ptrptr1 = &num2;
*ptr2 = 15;
*ptr3 = *ptr1;
printf("n1 = %d, n2 = %d, n3= %d\n",num1,num2,num3);

return 0;
}