#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const auto &src)
{
    cout << "event num =" << src.size() << "=" << endl;
    for (auto beg = src.begin(); beg != src.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    vector<int> myvec {0, 1, 2};
    vector<int> example {7, 8, 9};

    auto begin = myvec.begin();
    begin = myvec.insert(++begin, example.begin(), example.end());
    cout << *begin << endl;
    print(myvec);

    begin = myvec.begin();
    while (begin != myvec.end()) {
        ++begin;
        begin = myvec.insert(begin, 42);
        ++begin;
    }
    print(myvec);
    return 0;
}
