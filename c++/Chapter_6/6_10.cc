#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void change(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;

    change(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}
