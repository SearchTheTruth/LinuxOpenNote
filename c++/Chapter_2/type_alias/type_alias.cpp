#include <iostream>

typedef int *intptr;

int main()
{
    int a = 77;
    int b = 88;
    const intptr num1 = &a;
    const int *num2 = &a;

    *num1 += 1;
//    *num2 += 1; err

//    num1 = &b; err
    num2 = &b;

}
