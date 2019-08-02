#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;


int main()
{
    vector<int> src {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pos1 = src.begin();
    auto pos2 = src.end();

    pos1 += 2;

    vector<int> dts(pos1, pos2);

    int num = 9;

    vector<int>::iterator index = dts.begin();
    for (; index != dts.end(); index++) {
        if (*index == num)
            break;
    }
    if (index == dts.end())
        cout << "can not find num [" << num << "]" << endl;
    else
        cout << "find num [" << num << "]" << endl;
    return 0;
}
