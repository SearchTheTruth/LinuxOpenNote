#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string word;
    decltype(word.size()) index = 0;

    cout << "input something" << endl;
    cin >> word;

    while (index < word.size())
    {
        word[index] = 'X';
        ++index;
    }
    cout << word << endl;
    return 0;
}
