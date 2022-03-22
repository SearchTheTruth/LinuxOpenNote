#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string cmdline;
    bool exit = false;

    while (getline(cin, cmdline)) {
        istringstream strm(cmdline);
        string tmp;
        while (strm >> tmp) {
            if (tmp == "quit") {
                exit = true;
                break;
            }
            cout << tmp << endl;
        }
        if (exit)
            break;
    }
    return 0;
}