#include <iostream>
#include <string>
#include "HasPtr.h"

int main()
{
    HasPtr tom("tom");
    HasPtr tom_clone(tom);
    HasPtr tom_clone2 = tom;
    HasPtr tom_clone3;

    tom_clone3 = tom;
    tom.print();
    tom_clone.print();
    tom_clone2.print();
    tom_clone3.print();
    return 0;
}
