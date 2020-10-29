#include <stdio.h>
#include <stdlib.h>

int foo_1()
{
    static int a = 1;
    printf("%d\n", a);
}

int foo_2()
{
    static int a = 2;
    printf("%d\n", a);
}

int main()
{
    static int a = 3;
    printf("%d\n", a);
    foo_1();
    foo_2();

    return 0;
}


