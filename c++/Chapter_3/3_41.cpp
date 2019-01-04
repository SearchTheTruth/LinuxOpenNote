#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main()
{
    int array[10] = {0};

    for (int i = 0; i < 10; i++){
        array[i] = i;
    }

    for (auto i : array)
        cout << i << " ";
    cout << endl;

    vector<int> vec(begin(array), end(array));
    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    return 0;
}
