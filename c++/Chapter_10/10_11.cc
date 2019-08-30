#include <algorithm>
using std::sort;
using std::stable_sort;
using std::unique;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "print.h"

bool isShort(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    print(tmp);

    sort(tmp.begin(), tmp.end());
    print(tmp);

    auto end_unique = unique(tmp.begin(), tmp.end());
    print(tmp);

    tmp.erase(end_unique, tmp.end());
    print(tmp);

    stable_sort(tmp.begin(), tmp.end(), isShort);
    print(tmp);

    return 0;
}

