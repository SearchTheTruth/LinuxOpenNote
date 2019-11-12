#include <vector>
#include <algorithm>
#include "HasPtr_swap.h"

using namespace::std;

int main()
{
    vector<HasPtr> tmp{HasPtr("Tom"), HasPtr("Jack"), HasPtr("Alby"), HasPtr("Bruce")};

    for (auto& ele : tmp) {
        ele.print();
    }

    sort(tmp.begin(), tmp.end());
    for (auto& ele : tmp) {
        ele.print();
    }
    return 0;
}
