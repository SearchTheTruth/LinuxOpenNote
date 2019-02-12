#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void change(int &m, int &n)
{
    int tmp;
    tmp = m;
    m = n;
    n = tmp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;

    change(a, b);
    cout << a << " " << b << endl;
    return 0;
}
