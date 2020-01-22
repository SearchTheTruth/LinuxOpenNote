#include "compare.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    cout << "compare(1, 2) = " << compare(1, 2) << endl;

    cout << "compare(\"b\", \"a\") = " << compare("b", "a") << endl;

    cout << "compare(1, 1) = " << compare(1, 1) << endl;

    return 0;
}
