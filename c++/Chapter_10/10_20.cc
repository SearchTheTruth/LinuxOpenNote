#include <algorithm>

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    auto f = [](const string &s) -> bool {
        if (s.size() > 6)
            return true;
        else
            return false;
    };
    vector<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    cout << count_if(tmp.begin(), tmp.end(), f) << " words is longer than 6" << endl;
    return 0;
}
