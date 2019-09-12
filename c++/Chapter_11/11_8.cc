#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> svec;
    string tmp;
    while (cin >> tmp) {
        if (find(svec.begin(), svec.end(), tmp) == svec.end())
            svec.push_back(tmp);
    }

    for (auto const &str : svec) {
        cout << str << " ";
    }
    cout << endl;


}
