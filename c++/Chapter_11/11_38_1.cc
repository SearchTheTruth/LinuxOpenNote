#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    unordered_map<string, int> word_count;

    while (cin >> word)
        ++word_count[word];

    for (auto pair : word_count)
        cout << pair.first << " " << pair.second << endl;

    cout << "================" << endl;

    return 0;
}
