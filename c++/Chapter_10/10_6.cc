#include <algorithm>
using std::fill_n;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include "print.h"

int main()
{
    vector<int> intline {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(intline);

    fill_n(intline.begin(), intline.size(), 0);
    print(intline);

    return 0;
}
