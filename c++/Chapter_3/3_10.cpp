#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string s = "Hello, world!!";
    cout << "[Before]: " << s << endl;
    cout << "[After]: ";
    for (auto c : s) {
        if (ispunct(c))
            continue;
        cout << c;
    }
    cout << endl;

    return 0;
}
