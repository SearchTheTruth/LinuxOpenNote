#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int num;
    cin >> num;

    if (num % 2)
        cout << "odd"<< endl;
    else
        cout << "double" << endl;

    return 0;
}
