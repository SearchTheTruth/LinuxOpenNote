#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> numbers;

    for (int i = 0; i < 10; i++)
        numbers.push_back(i);

    for (auto index : numbers)
        cout << index << " ";
    cout << endl;

    for (auto iterator = numbers.begin(); iterator != numbers.end(); ++iterator)
        *iterator *= 2;

    for (auto index : numbers)
        cout << index << " ";
    cout << endl;

    return 0;
}
