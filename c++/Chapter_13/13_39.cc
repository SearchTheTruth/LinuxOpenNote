#include "Message.h"
#include <iostream>

int main()
{
    Message hello("HelloWorld");
    Floder init("Init");
    hello.save(init);
    show(hello);
    show(init);

    Message hello1(hello);
    show(hello1);
    show(init);

    Message hello2;
    hello2 = hello;
    show(hello2);
    show(init);

    Floder init1(init);
    show(hello);
    show(hello1);
    show(hello2);
    show(init1);
    show(init);

    return 0;
}
