#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    map<string, int> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
        }
    }

    for (auto wp : word_count) {
        cout << wp.first << " = " << wp.second;
        cout << endl;
    }

    return 0;
}
