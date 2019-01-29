#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;


int main()
{
    vector<int> shortNum = {0, 1, 1, 2};
    vector<int> longNum = {0, 1, 1, 2, 3, 7, 8};
    decltype(shortNum.size()) length, index;

    if (shortNum.size() > longNum.size())
        length = longNum.size();
    else
        length = shortNum.size();

    for (index = 0; index != length; ++index) {
        if (shortNum[index] != longNum[index])
            break;
    }

    if (index == length)
        cout << "shortNum is part of longNum" << endl;
    else
        cout << "shortNum is not part of longNum" << endl;

    return 0;
}
