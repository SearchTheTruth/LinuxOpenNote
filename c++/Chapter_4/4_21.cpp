#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;

    for (int index = 0; index < 10; index++)
        vec.push_back(index);

    for (auto &num : vec)
        cout << num << " ";
    cout << endl;

    for (auto &num : vec)
        num % 2 ? num *= 2 : num;

    for (auto &num : vec)
        cout << num << " ";
    cout << endl;

    return 0;
}
