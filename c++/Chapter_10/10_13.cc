#include <algorithm>
using std::partition;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "print.h"

bool isLess5char(const string &str)
{
    return str.size() < 5;
}

int main()
{
    vector<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    print(tmp);

    auto large = partition(tmp.begin(), tmp.end(), isLess5char);
    print(tmp);

    print(vector<string> (large, tmp.end()));
    return 0;
}
