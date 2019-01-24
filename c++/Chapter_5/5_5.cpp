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
        if (tmp < 60)
            cout << grade[0] << endl;
        else if (tmp >= 60 && tmp < 70)
            cout << grade[1] << endl;
        else if (tmp >= 70 && tmp < 80)
            cout << grade[2] << endl;
        else if (tmp >= 80 && tmp < 90)
            cout << grade[3] << endl;
        else if (tmp >= 90 && tmp < 100)
            cout << grade[4] << endl;
        else if (tmp == 100)
            cout << grade[5] << endl;
        else
            cout << "illegal" << endl;
    }

    return 0;
}
