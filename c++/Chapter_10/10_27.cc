#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <list>

using namespace std;
using namespace placeholders;

int main()
{
    vector<int> tmp{1, 2, 2, 3, 3, 1};
    list<int> lst;
    unique_copy(tmp.begin(), tmp.end(), back_inserter(lst));

    for(auto str : tmp)
        cout << str << " ";
    cout << endl;

    for(auto str : lst)
        cout << str << " ";
    cout << endl;

    auto unique_end = unique(tmp.begin(), tmp.end());

    for(auto str : vector<int> (tmp.begin(), unique_end))
        cout << str << " ";
    cout << endl;

    return 0;
}
