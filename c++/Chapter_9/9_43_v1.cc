#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void replace(string &s, const string &oldVal, const string &newVal)
{
    auto curr = s.begin();
    while (curr <= s.end() - oldVal.size()) {
        string tmp (curr, curr + oldVal.size());
        cout << "tmp = " << tmp << endl;
        if (oldVal == tmp) {
            curr = s.erase(curr, curr + oldVal.size());
            curr = s.insert(curr, newVal.begin(), newVal.end());
            curr += newVal.size();
        } else {
            ++curr;
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
