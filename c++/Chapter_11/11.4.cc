#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm> //transform

using namespace std;


void wordLower(string &word)
{
    for (auto &ch : word) {
        if (isupper(ch))
            ch = tolower(ch);
    }
}

/*string变为小写去除非字母符号*/
void wordProcess(string &word)
{
    auto findSymbol = [](const char &ch) -> bool {
        if(ch < 'a' || ch > 'z')
            return true;
        else
            return false;
    };
    wordLower(word);
    auto pos = word.begin();
    while ((pos = find_if(pos, word.end(), findSymbol))
            != word.end()) {
        pos = word.erase(pos);
    }
}

int main()
{
    map<string, size_t> wordCount;
    string word;
    while (cin >> word) {
        wordProcess(word);
        ++wordCount[word];
    }

    cout << endl << "==out put==" << endl;
    for (auto ele : wordCount) {
        cout << ele.first << " = " << ele.second << endl;
    }
    cout << endl;
    return 0;
}
