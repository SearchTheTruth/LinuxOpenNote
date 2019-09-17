#include <vector>
#include <utility>      //pair
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<pair<string, int>> vpair;
    /*1th*/
    pair<string, int> tmp;
    while (cin >> tmp.first >> tmp.second) {
        vpair.push_back(tmp);
    }

    /*2th*/
    string str;
    int i;
    while (cin >> str >> i) {
        vpair.push_back(pair<string,int> (str, i));
    }

    /*3th*/
    string str1;
    int i1;
    while (cin >> str >> i) {
        vpair.push_back(make_pair(str1, i1));
    }

    /*4th*/
    string str2;
    int i2;
    while (cin >> str >> i) {
        vpair.push_back({str2, i2});
    }

    cout << "==output==" << endl;
    cout << "vpair.size() = " << vpair.size() << endl;
    for (const auto &p : vpair) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    return 0;
}
