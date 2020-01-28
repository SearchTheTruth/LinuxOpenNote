#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "find_template.h"

using namespace std;

int main()
{
    vector<int> vi{0, 1, 2, 3, 4};
    list<string> ls{"a", "b", "c"};

    auto vret = find(vi.begin(), vi.end(), 5);
    if (vret != vi.end())
        cout << *vret << endl;
    else
        cout << "no match item" << endl;

    auto lret = find(ls.cbegin(), ls.cend(), "b");
    cout << *lret << endl;
    return 0;
}
