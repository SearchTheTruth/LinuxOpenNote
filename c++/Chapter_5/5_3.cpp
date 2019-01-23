#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int val = 0, sum = 0;
    while (sum += val, ++val, val <= 10)
        cout << "sum = " << sum << endl;

    return 0;
}
