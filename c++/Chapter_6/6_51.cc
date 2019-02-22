#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void f()
{
    cout << "void f()" << endl;
}

void f(int)
{
    cout << "void f(int)" << endl;
}

void f(int, int)
{
    cout << "void f(int, int)" << endl;
}

void f(double, double = 3.14)
{
    cout << "void f(double, double = 3.14)" << endl;
}

int main()
{
//    f(2.56, 42); 二义性
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}
