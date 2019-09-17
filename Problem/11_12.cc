#include <vector>
#include <utility>      //pair
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<pair<string, int>> vpair;
    pair<string, int> tmp;
    while (cin) {
        cin >> tmp.first;
        cin >> tmp.second;
        vpair.push_back(tmp);
    }

    cout << "==output==" << endl;
    cout << "vpair.size() = " << vpair.size() << endl;
    for (const auto &p : vpair) {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    return 0;
}
