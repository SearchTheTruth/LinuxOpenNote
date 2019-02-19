#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int &outputArray(int *p, int index)
{
    cout << p[index] << " ";

    return p[index];
}

int main()
{
    int tmp[5] = {8, 9, 3, 5, 0};

    for (int i = 0; i < 5; i++) {
        outputArray(tmp, i) = i + 10;
    }
    cout << endl;

    for (auto &m : tmp)
        cout << m << " ";
    cout << endl;

    return 0;
}
