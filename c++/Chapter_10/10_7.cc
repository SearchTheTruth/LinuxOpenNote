#include <algorithm>
using std::copy;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include "print.h"

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iterator>
using std::back_inserter;

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;

    while (cin >> i) {
        lst.push_back(i);
    }
    copy(lst.begin(), lst.end(), back_inserter(vec));

    print(lst);
    print(vec);

    vector<int> tmp;
    tmp.reserve(10);
    fill_n(back_inserter(tmp), 7, 0);
    print(tmp);
    cout << "tmp.capacity = " << tmp.capacity() << endl;

    return 0;
}
