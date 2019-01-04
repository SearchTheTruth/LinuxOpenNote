#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };


    cout << "version 1: " << endl;
    for (auto &p : ia){
        for (auto &q : p)
            cout << q << " ";
        cout << endl;
    }
    cout << "=================" << endl;

    cout << "version 2: " << endl;
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    cout << "=================" << endl;

    cout << "version 3: " << endl;
    for (auto *row = ia; row != ia + 3; ++row) {
        for (auto *col = *row; col != *row + 4; ++col)
            cout << *col << " ";
        cout << endl;
    }
    cout << "=================" << endl;

    return 0;
}
