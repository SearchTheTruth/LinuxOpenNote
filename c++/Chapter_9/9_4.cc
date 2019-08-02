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

    int num = 2;
    bool find = false;

    for (const auto &index : dts) {
        if (index == num) {
            find = true;
            cout << "find num[" << num << "]" << endl;
            break;
        }
    }
    if (!find)
        cout << "can not find num [" << num << "]" << endl;
    return 0;
}
