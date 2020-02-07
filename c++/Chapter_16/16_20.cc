#include "box_print.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{0, 1, 2};

    box_print(vi.begin(), vi.end());
    return 0;
}
