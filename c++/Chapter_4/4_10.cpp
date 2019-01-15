#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int num;
    while (cin >> num && num != 42) {
        cout << num << endl;
    }

    return 0;
}
