#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main ()
{
    vector<int> box;
    int num;

    while (cin >> num) {
        cout << num << endl;
        if (0 == num)
            break;
        box.push_back(num);
    }

    /*
     * 要注意范围fory循环中index表示的是向量中的每个元素，而不是向量下标！
    for (auto index : box)
        cout << box[index] << " ";
    cout << endl;
    */

    for (auto index : box)
        cout << index << " ";
    cout << endl;

    box = {7, 9, 17};

    cout << box[0] << " ";
    cout << box[1] << " ";
    cout << box[2] << " ";
    cout << box[3] << " ";
    return 0;
}

