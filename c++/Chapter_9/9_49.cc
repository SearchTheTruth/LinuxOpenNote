#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    string word, maxWord;
    string up("df"), down("pg");
    size_t maxSize = 0;

    while (cin >> word) {
        if (word.find_first_of(up) == string::npos &&
                word.find_first_of(down) == string::npos) {
            if (maxSize < word.size()) {
                maxSize = word.size();
                maxWord = word;
            }
        }
    }

    cout << maxWord << endl;
    return 0;
}
