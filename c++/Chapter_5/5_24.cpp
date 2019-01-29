#include <iostream>
#include <stdexcept>

using std::endl;
using std::cout;
using std::cin;
using std::runtime_error;

int main()
{
    int fir, sec;

    if (cin >> fir >> sec) {
            if (!sec)
                throw runtime_error("sec should not equal 0");

        cout << fir << " / " << sec << " = " << fir / sec << endl;
    }

    return 0;
}
