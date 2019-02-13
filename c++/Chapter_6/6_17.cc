#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int checkUpper(const string &str)
{
    for (auto ch : str) {
        if (isupper(ch))
            return 1;
    }
    return 0;
}

int changelower(string &str)
{
    for (auto &ch : str) {
        ch = tolower(ch);
    }
    return 0;
}

int main()
{
    string exp = "HelloWORLD";

    cout << "origin = " << exp << endl;
    cout << (checkUpper(exp) ? "have upper letter" : "don't have upper letter") << endl;
    changelower(exp);
    cout << "change all letter to lower = " << exp << endl;
    return 0;
}
