#include "begin_end_template.h"
#include <iostream>

using namespace std;

int main()
{
    int iarr[] = {0, 1, 2};

    cout << "start addr: " << iarr << endl;
    cout << "begin addr: " << begin(iarr) << endl;
    cout << "end   addr: " << end(iarr) << endl;

    return 0;
}
