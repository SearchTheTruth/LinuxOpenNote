#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


int main ()
{
    string text;

    getline(cin, text);
    cout << "ORIGIN: " << text << endl;

    for (auto it = text.begin();
            it != text.end() && !isspace(*it); ++it)
        *it = toupper(*it);
    cout << "CHANGED: " << text << endl;

    cout << "============================" <<endl;

    return 0;
}
