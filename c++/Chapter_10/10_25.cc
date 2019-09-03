#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

void print(const string &s)
{
    cout << s << " ";
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggest(vector<string> org, string::size_type sz)
{
    if (org.empty())
        return;
    sort(org.begin(), org.end());
    stable_sort(org.begin(), org.end(), [](const string &s1, const string &s2)
            {return s1.size() < s2.size();});
    auto big = partition(org.begin(), org.end(), bind(check_size, _1, sz));
    cout << big - org.begin() << " words is longer than " << sz <<" character" << endl;
    for_each(org.begin(), big, print);
}

int main()
{
    vector<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    biggest(tmp, 5);
    cout << endl;
    return 0;
}
