#ifndef __PRINT_TEMPLATE_H
#define __PRINT_TEMPLATE_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename Array> void print(const Array &arr)
{
    for (const auto &elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

#endif
