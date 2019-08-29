#include <algorithm>
using std::sort;
using std::unique;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "print.h"

int main()
{
    vector<int> tmp{1, 3, 234, 54, 67, 768, 3, 4324, 4, 65, 5, 6, 7, 5, 4, 3, 4,6,7 ,8};
    print(tmp);

    sort(tmp.begin(), tmp.end());
    print(tmp);

    auto end_unique = unique(tmp.begin(), tmp.end());
    print(tmp);

    tmp.erase(end_unique, tmp.end());
    print(tmp);

    return 0;
}

