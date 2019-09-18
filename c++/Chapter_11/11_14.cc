#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int main()
{
    map<string, vector<pair<string, string>>> familys;
    string fname;
    string cname;
    string cdate;

    cout << "enter family name" << endl;
    cin >> fname;
    cout << "enter child name" << endl;
    while (cin >> cname >> cdate)
        familys[fname].push_back({cname, cdate});

    cout << "==output==" << endl;
    for (const auto &ele : familys) {
        cout << "family name = " << ele.first << endl;
        for (const auto &cpair : ele.second) {
            cout << "child name = " << cpair.first << endl;
            cout << "child date = " << cpair.second << endl;
        }
    }
    return 0;
}
