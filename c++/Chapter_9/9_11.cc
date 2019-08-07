#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const vector<int> &src)
{
    cout << "event num =" << src.size() << "=" << endl;
    for (const auto &ev : src) {
        cout << ev << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    vector<int> src {0, 1, 2, 3, 4};
    print(src);

    //#1
    vector<int> th1;
    print(th1);

    //#2
    vector<int> th2(src);
    print(th2);

    //#3
    vector<int> th3 = src;
    print(th3);

    //#4
    vector<int> th4 {77, 88, 99};
    print(th4);

    //#5
    vector<int> th5 = {55, 66};
    print(th5);

    //#6
    vector<int> th6(src.begin(), src.end());
    print(th6);

    return 0;
}
