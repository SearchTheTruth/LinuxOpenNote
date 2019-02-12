#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int call_add()
{
    static int ctr = 0;
    return ctr++;
}

int main()
{
    int ret;

    for (int i = 0; i < 10; i++) {
        ret = call_add();
        cout << ret << endl;
    }

    return 0;
}
