#include <stdlib.h>
#include <stdio.h>

int foo();

int a = 1;
int b = 2;

int main()
{
    a = 1;

    foo();
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    return 0;
}
