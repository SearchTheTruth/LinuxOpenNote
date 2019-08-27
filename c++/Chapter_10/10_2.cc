#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <algorithm>
using std::count;

#include <list>
using std::list;

#include <string>
using std::string;

int main()
{
    string ch;
    list<string> strline;

    while (cin >> ch) {
        strline.push_back(ch);
    }

    cout << "me is appear " << count(strline.begin(), strline.end(), "me") << " times" << endl;
    return 0;
}
