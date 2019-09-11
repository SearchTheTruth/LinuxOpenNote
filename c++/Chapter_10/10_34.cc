#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> tmp {0, 1, 2, 3, 4, 5};

    cout << "reverse iterator" << endl;
    for (auto rbeg = tmp.crbegin(); rbeg != tmp.crend(); ++rbeg) {
        cout << *rbeg << " ";
    }
    cout << endl;

    cout << "normal iterator" << endl;
    for (auto beg = tmp.cbegin(); beg != tmp.cend(); ++beg) {
        cout << *beg << " ";
    }
    cout << endl;
    return 0;
}
