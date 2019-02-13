#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int compare(int a, const int *b)
{
    return a > *b ? a : *b;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << compare(m, &n) << endl;

    return 0;
}

