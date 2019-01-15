#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int x[10];
    int *p = x;

    cout << sizeof(x) / sizeof(*x) << " 10" << endl;
    cout << sizeof(p) / sizeof(*p) << " 2" << endl;

    return 0;
}

