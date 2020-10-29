#include <stdlib.h>
#include <stdio.h>

int foo();

int a;

int main()
{
    a = 1;

    foo();
    printf("%d\n", a);
    return 0;
}
