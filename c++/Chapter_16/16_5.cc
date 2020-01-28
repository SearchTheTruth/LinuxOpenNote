#include "print_template.h"
#include <string>

using std::string;

int main()
{
    int iarr[] = {0, 1, 2};
    string sarr[] = {"a", "b", "c"};

    print(iarr);
    print(sarr);

    return 0;
}
