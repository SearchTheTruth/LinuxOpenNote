#include "person.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
    struct person jim = {"JIM", "NewYork"};

    cout << jim.isName() << " is live in " << jim.isAddr() << endl;
    return 0;
}
