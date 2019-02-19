#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int outputVector(vector<int>::iterator beg, vector<int> &org)
{
    cout << *beg++ << " ";

    if (beg == org.end()) {
        cout << endl;
        return 0;
    } else {
        return outputVector(beg, org);
    }
}

int main()
{
    vector<int> tmp = {1, 2, 3, 4, 5};

    outputVector(tmp.begin(), tmp);

    return 0;
}
