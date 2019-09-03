#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int v = 10;
    auto f = [v]() mutable {return ++v;};
    v = 0;
    cout << f() << endl;
    return 0;
}
