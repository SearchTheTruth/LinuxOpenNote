#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string one, two, three;
    string total;

    cout << "pls input three words" << endl;

    cin >> one >> two >> three;
    total = one + two + three;
    cout << total << endl;
    total = one + " " + two + " " + three;
    cout << total << endl;
}
