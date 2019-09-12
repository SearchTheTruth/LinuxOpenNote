#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> wordCount;
    string word;
    while (cin >> word) {
        ++wordCount[word];
    }

    cout << endl << "==out put==" << endl;
    for (auto ele : wordCount) {
        cout << ele.first << " = " << ele.second << endl;
    }
    cout << endl;
    return 0;
}
