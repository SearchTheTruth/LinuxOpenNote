#include <iostream>
#include <initializer_list>


using std::cout;
using std::cin;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> elem)
{
    int total = 0;

    for (const auto &i : elem) {
        total += i;
        cout << i << " ";
    }
    cout << endl;

    return total;
}

int main()
{
    cout << sum({3, 2, 1, 7}) << endl;

    return 0;
}

