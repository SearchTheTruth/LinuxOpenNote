#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int exchangePtr(int **a, int **b)
{
    int *tmp;

    if (!a || !b) {
        cout << "ptr error\n";
        return -1;
    }

    tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int main()
{
    int m, n;
    int *ptr_m, *ptr_n;

    m = 1;
    n = 7;
    ptr_m = &m;
    ptr_n = &n;

    cout << "[Addr]ptr_m = " << ptr_m << "\t" << "[Val]ptr_m = " << *ptr_m << endl;
    cout << "[Addr]ptr_n = " << ptr_n << "\t" << "[Val]ptr_n = " << *ptr_n << endl;

    exchangePtr(&ptr_m, &ptr_n);
    cout << "[Addr]ptr_m = " << ptr_m << "\t" << "[Val]ptr_m = " << *ptr_m << endl;
    cout << "[Addr]ptr_n = " << ptr_n << "\t" << "[Val]ptr_n = " << *ptr_n << endl;
    return 0;
}
