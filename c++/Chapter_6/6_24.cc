#include <iostream>

using std::cout;
using std::cin;
using std::endl;


void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i) {
        cout << ia[i] << endl;
    }
}

int main()
{
    int exp[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    print(exp);

    return 0;

}
