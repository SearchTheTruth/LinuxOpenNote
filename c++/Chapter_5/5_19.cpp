#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string first, second;
    do {
        cout << "please input two string" << endl;
        cin >> first >> second;
        if (first.size() < second.size())
            cout << first << endl;
        else
            cout << second << endl;
    } while (cin);
    return 0;
}
