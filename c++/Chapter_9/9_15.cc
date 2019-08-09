#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    vector<int> vec_1 {0, 1, 2, 3};
    vector<int> vec_2 {4, 5, 6, 7};

    cout << (vec_1 == vec_2) << endl;
    return 0;
}

