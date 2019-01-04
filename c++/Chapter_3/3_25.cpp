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
    vector<unsigned int> scores(11, 0);
    unsigned int grade;

    auto head = scores.begin();

    while (cin >> grade) {
        if (grade > 100) {
            cout << grade << " is illegal" << endl;
            break;
        }

        *(head + (grade/10)) += 1;
    }

    for (auto i : scores)
        cout << i << " ";
    cout << endl;

    return 0;
}
