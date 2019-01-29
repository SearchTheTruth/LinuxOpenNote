#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string cur, pre;
    while (cin >> cur)
    {
        if (cur == pre)
            break;
        else
            pre = cur;
    }
    if (cin.eof())
        cout << "no repeate word" << endl;
    else
        cout << pre << endl;
    return 0;
}
