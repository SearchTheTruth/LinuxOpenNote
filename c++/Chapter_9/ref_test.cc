#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int a = 7;
    int &b = a;
    auto c = b;

    cout << a << " " << b << " " << c << endl;
    ++a;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
