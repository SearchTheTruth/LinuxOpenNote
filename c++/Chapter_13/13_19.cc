#include "Employee.h"

int main()
{
    Employee tom("tom");
    Employee tom_clone(tom);
    Employee tom_clone2 = tom;
    Employee tom_empty;
    tom_empty = tom;
    tom.print();
    tom_clone.print();
    tom_clone2.print();
    tom_empty.print();
}
