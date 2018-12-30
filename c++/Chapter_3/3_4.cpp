#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string first, second;

    cout << "pls input two world" << endl;
    cin >> first;
    cin >> second;

    if (first != second) {
        if (first > second)
            cout << first << endl;
        else
            cout << second << endl;
    } else
        cout << "two world are same" << endl;

    cout << "pls input two world" << endl;
    cin >> first;
    cin >> second;

    if (first.size() != second.size())
    {
        if (first.size() > second.size())
            cout << first << endl;
        else
            cout << second << endl;
    } else
        cout << "two word length are same" << endl;
}
