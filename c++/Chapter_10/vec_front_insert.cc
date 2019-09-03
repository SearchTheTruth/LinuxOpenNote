#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main()
{
    vector<int> org {0, 1, 2, 3};
    vector<int> dst;

    copy(org.begin(), org.end(), front_inserter(dst));

    for (auto num : dst)
        cout << num << " ";
    cout << endl;
    return 0;
}
