#include <iostream>
#include <string>
#include "HasPtr_copy_like_ptr.h"

int main()
{
    HasPtr tom("tom");
    HasPtr tom_clone(tom);
    HasPtr tom_clone2 = tom;
    HasPtr jim("jim");

    tom.print();
    tom_clone.print();
    tom_clone2.print();
    jim.print();
    jim = tom;
    jim.print();
    return 0;
}
