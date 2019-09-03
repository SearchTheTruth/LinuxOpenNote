#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    string str ("computer");
    vector<int> tmp {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto compare = bind(check_size, str, _1);
    auto pos = find_if(tmp.begin(), tmp.end(), compare);
    cout << "str length = " << str.size() << endl;
    cout << "tmp = " << *pos << endl;
    return 0;
}
