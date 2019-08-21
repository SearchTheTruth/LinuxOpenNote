#include <list>
using std::list;

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
    cout << "update" << endl;
    list<int> mylist {0, 1, 2, 3, 4, 5, 6, 7, 9};
    print(mylist);
    auto cur = mylist.begin();
    while (cur != mylist.end()) {
        if (*cur & 0x1 == 0x1) {
            cur = mylist.insert(cur, *cur++);
            ++cur;
        } else {
            cur = mylist.erase(cur);
        }
    }
    print(mylist);
    return 0;
}
