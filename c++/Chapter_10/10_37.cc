#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> org {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> tmp, dst;
    tmp.assign(org.begin() + 3, org.begin() + 7);
    copy(tmp.crbegin(), tmp.crend(), back_inserter(dst));

    cout << "org" << endl;
    for (auto nu : org)
        cout << nu << " ";
    cout << endl;
    cout << "tmp" << endl;
    for (auto nu : tmp)
        cout << nu << " ";
    cout << endl;
    cout << "dst" << endl;
    for (auto nu : dst)
        cout << nu << " ";
    cout << endl;
    dst.clear();
    copy(org.crbegin() + 3, org.crbegin() + 8, back_inserter(dst));
    cout << "dst v2" << endl;
    for (auto nu : dst)
        cout << nu << " ";
    cout << endl;

    return 0;
}
