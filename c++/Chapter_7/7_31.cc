#include <iostream>

class Y;
class X {
    Y *yptr;
};

class Y {
    X xclass;
};

int main()
{
    X x1;
    Y y1;

    std::cout << "OK\n";
    return 0;
}
