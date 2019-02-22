#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

constexpr bool isShorter(const string &s1, const string &s2)
{
    return (s1.size() < s2.size()) ? true : false;
}


int main()
{

    constexpr bool stat = isShorter("Short", "long");

    cout << stat << endl;

    return 0;
}
