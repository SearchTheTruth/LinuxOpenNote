#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string word;

    cout << "input something" << endl;
    cin >> word;

    for (auto &ch : word)
        ch = 'X';

    cout << word <<endl;
    return 0;
}
