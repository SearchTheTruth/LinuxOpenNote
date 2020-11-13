#include <stdio.h>

extern int foo1();
extern int foo2();
int main()
{
    fputs("enter main", stdout);
    foo1();
    foo2();

    return 0;
}
