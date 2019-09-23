#include <set>
#include <iostream>

using namespace std;

int main()
{
    set<int> tmp{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "lower " << *tmp.lower_bound(3) << endl;
    cout << "upper " << *tmp.upper_bound(3) << endl;
    return 0;
}
