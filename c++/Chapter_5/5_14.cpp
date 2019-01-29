#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    unsigned int cur = 1, max = 0;
    string curStr, preStr, maxStr;

    while (cin >> curStr)
    {
        if (curStr == preStr) {
            ++cur;
        } else {
            if (cur > max) {
                max = cur;
                maxStr = preStr;
            }
            preStr = curStr;
            cur = 1;
        }
    }

    if (1 == max)
        cout << "no repeat word" << endl;
    else
        cout << maxStr <<": " << max << "times." << endl;
    return 0;
}
