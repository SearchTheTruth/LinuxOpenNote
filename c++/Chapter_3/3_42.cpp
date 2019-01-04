#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::begin;
using std::end;

int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    for (auto i : vec)
        cout << i << " ";
    cout << endl;

    const int sz = vec.size();
    int array[sz] = {0};

    for (int i = 0; i < sz; i++)
        array[i] = vec[i];

    for (auto i : array)
        cout << i << " ";
    cout << endl;
}

