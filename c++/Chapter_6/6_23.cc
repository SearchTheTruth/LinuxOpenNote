#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::begin;
using std::end;

int print(const int *beg, const int *end)
{
    while (beg != end) {
        cout << *beg++ << endl;
    }
    return 0;
}

int print(const int *beg, int length)
{
    for (int i = 0; i < length; i++) {
        cout << beg[i] << endl;
    }
    return 0;
}

int main()
{
    int i = 0;
    int j[2] = {0, 1};

    print(&i, 1);
    print(begin(j), end(j));
    return 0;
}


