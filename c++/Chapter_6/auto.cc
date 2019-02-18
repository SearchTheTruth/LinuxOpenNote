#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int tmp[3] = {1, 2, 3};

    for(int n = 0; n < 3; n++)
        cout << "ori:[" << &tmp[n]<< "]" << tmp[n] << " ";
    cout << endl;

    for(auto i : tmp) {
        cout << "val:[" << &i<< "]" << i << " ";
        i = 7;
    }
    cout << endl;
    cout << "change all element to 7\n";

    for(int n = 0; n < 3; n++)
        cout << "ori:[" << &tmp[n]<< "]" << tmp[n] << " ";
    cout << endl;

    for(auto &j : tmp) {
        cout << "ref:[" << &j<< "]" << j << " ";
        j = 7;
    }
    cout << endl;
    cout << "change all element to 7\n";

    for(int n = 0; n < 3; n++)
        cout << "ori:[" << &tmp[n]<< "]" << tmp[n] << " ";
    cout << endl;

    return 0;
}
