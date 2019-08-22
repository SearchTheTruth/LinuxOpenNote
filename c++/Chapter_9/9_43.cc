#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

string &replace_str(string &s, string &oldVal, string &newVal)
{
    auto spos = s.begin();
    auto opos = oldVal.begin();
    string::iterator start, end;
    bool init = false;

    if (oldVal.empty()) {
        cout << "oldVal is empty, can't replace" << endl;
        return s;
    }
    while (spos != s.end()) {
        if (*spos == *opos) {
            if (!init) {
                start = spos;
                init = true;
            }
        } else if (*spos != *opos) {
            if (init)
                break;
            }
        }
        ++spos;
        ++opos;
        if (init)
            end = spos;
        if (opos == oldVal.end())
            break;
    }
    if (init) {
        start = s.erase(start, end);
        s.insert(start, newVal.begin(), newVal.end());
    } else {
        cout << "can't find oldVal(" << oldVal << "), stop replace" << endl;
    }
    return s;
}


int main()
{
    string s, oldVal, newVal;
    while (1) {
        cout << "please enter three string :s, oldVal, newVal" << endl;
        cin >> s;
        cin >> oldVal;
        cin >> newVal;
        cout << s << " " << oldVal << " " << newVal << " " << endl;
        cout << "after replace: " << replace_str(s, oldVal, newVal) << endl;
    }
    return 0;
}
