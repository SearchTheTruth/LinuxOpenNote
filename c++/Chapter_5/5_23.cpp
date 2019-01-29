#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main()
{
    int fir, sec;

    if (cin >> fir >> sec) {
        cout << fir << " / " << sec << " = " << fir / sec << endl;
    }

    return 0;
}
