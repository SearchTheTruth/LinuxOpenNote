#include <iostream>
#include <stdexcept>

using std::endl;
using std::cout;
using std::cin;
using std::runtime_error;

int main()
{
    int fir, sec;

    while (cin >> fir >> sec) {
        try {
            if (!sec)
                throw runtime_error("sec should not equal 0");
        }
        catch (runtime_error err) {
            char ch;
            cout << err.what() << endl;
            cout << "want input again? Y/N" << endl;
            cin >> ch;
            if (ch != 'Y' && ch != 'y')
                break;
            else
                continue;
        }

        cout << fir << " / " << sec << " = " << fir / sec << endl;
        break;
    }

    return 0;
}
