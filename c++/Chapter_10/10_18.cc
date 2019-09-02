#include <algorithm>
//using std::partition; using std::sort; using std::stable_sort; using std::for_each;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const string &s)
{
    cout << s << " ";
}

void biggest(vector<string> org, string::size_type sz)
{
    if (org.empty())
        return;
    sort(org.begin(), org.end());
    stable_sort(org.begin(), org.end(), [](const string &s1, const string &s2)
            {return s1.size() < s2.size();});
    auto big = partition(org.begin(), org.end(), [sz](const string &s)
            {return s.size() < sz;});
    cout << org.end() - big << " words is longer than " << sz <<" character" << endl;
    for_each(big, org.end(), print);
}

int main()
{
    vector<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    biggest(tmp, 5);
    cout << endl;
    return 0;
}
