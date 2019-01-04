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
    int tmp;

    while (cin >> tmp)
        numbers.push_back(tmp);

    for (auto i : numbers)
        cout << i << " ";
    cout << endl;

    int sum;
    for (auto head = numbers.begin(); head != numbers.end() - 1; ++head) {
        sum = *head + *(head + 1);
        cout << *head << " + " << *(head + 1) << " = " << sum << endl;
    }

    cout << "===========================" << endl;

    auto tail = numbers.end();
    int i = 0;
    for (auto head = numbers.begin(); head != tail; ++head, ++i) {
        if (head != tail - 1 - i) {
            if (head > tail - 1 - i)
                break;
            sum = *head + *(tail - 1 - i);
            cout << *head << " + " << *(tail - 1 - i) << " = " << sum << endl;
        } else {
            cout << *head << " = " << *head << endl;
            break;
        }
    }

    return 0;
}
