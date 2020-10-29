#include <stdlib.h>
#include <stdio.h>

int foo();

int a = 1;

int main()
{
    foo();
    printf("%d\n", a);
    return 0;
}
