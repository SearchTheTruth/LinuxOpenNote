#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main ()
{
    vector<int> num_line;
    int num, sum;

    while (cin >> num)
        num_line.push_back(num);

    auto length = num_line.size();
    cout << "number of digits: " << length << endl;

    decltype(num_line.size()) index;
    for (index = 0; index < length - 1; index++) {
        sum = num_line[index] + num_line[index + 1];
        cout << num_line[index] << " + " << num_line[index + 1] << " = " << sum << endl;
    }

    return 0;
}
