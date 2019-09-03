#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;

int main()
{
    vector<int> tmp {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> back;
    list<int> front;
    list<int> ist;

    copy(tmp.begin(), tmp.end(), back_inserter(back));
    copy(tmp.begin(), tmp.end(), front_inserter(front));
    copy(tmp.begin(), tmp.end(), inserter(ist, ist.begin()));

    for (auto n : back)
        cout << n << " ";
    cout << "back====" << endl;

    for (auto n : front)
        cout << n << " ";
    cout << "front====" << endl;

    for (auto n : ist)
        cout << n << " ";
    cout << "ist====" << endl;

    return 0;
}
