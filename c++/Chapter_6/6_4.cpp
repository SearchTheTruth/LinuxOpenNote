#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fact(int val)
{
    int ret = 1;

    while (val > 1) {
        ret *= val--;
    }

    return ret;
}


int main()
{
    int num;

    cout << "enter a digital\n";

    if (cin >> num) {
        cout << num << "! = " << fact(num) << endl;
    }

    return 0;
}
