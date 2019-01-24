#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const vector<string> grade = {"F", "D", "C", "B", "A", "A++"};
    int tmp;
    while (cin >> tmp) {
        tmp < 60 ? cout << grade[0] << endl : (tmp >= 60 && tmp < 70 ?
                   cout << grade[1] << endl : (tmp >= 70 && tmp < 80 ?
                   cout << grade[2] << endl : (tmp >= 80 && tmp < 90 ?
                   cout << grade[3] << endl : (tmp >= 90 && tmp < 100 ?
                   cout << grade[4] << endl : cout << grade[5] << endl))));
    }

    return 0;
}
