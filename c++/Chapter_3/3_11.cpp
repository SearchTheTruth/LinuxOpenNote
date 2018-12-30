#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    const string s = "Keep out!";
    for (auto &c : s)
        cout << c << endl;
    return 0;
}
