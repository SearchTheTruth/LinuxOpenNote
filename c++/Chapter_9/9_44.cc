#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void replace(string &s, const string &oldVal, const string &newVal)
{
    unsigned int idx = 0;
    while (idx <= s.size() - oldVal.size()) {
        if (oldVal == string(s, idx, oldVal.size())) {
            s.replace(idx, oldVal.size(), newVal);
            idx += newVal.size();
        } else {
            ++idx;
        }
    }
}

int main()
{
    string s("hello");
    cout << s << endl;
    replace(s, "lo", "ll");
    cout << s << endl;
    replace(s, "el", "ll");
    cout << s << endl;
    return 0;
}
