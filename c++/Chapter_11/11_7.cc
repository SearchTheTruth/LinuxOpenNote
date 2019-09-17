#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    map<string, vector<string>> familys;
    string fname;
    string cname;

    cout << "enter family name" << endl;
    cin >> fname;
    cout << "enter child name" << endl;
    while (cin >> cname)
        familys[fname].push_back(cname);

    cout << "==output==" << endl;
    for (const auto &ele : familys) {
        cout << "family name = " << ele.first << endl;
        for (const auto child : ele.second) {
            cout << "child name = " << child << endl;
        }
    }
    return 0;
}
