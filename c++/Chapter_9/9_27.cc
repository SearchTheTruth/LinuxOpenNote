#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <forward_list>
using std::forward_list;

void print(const auto &src)
{
    for (auto beg = src.begin(); beg != src.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    forward_list<int> flist{0, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto prev = flist.before_begin();
    auto cur = flist.begin();

    print(flist);
    cout << endl;
    while (cur != flist.end()) {
        if (*cur & 0x1 == 0x1) {
            cur = flist.erase_after(prev);
        } else {
            prev = cur;
            ++cur;
        }
    }
    print(flist);
    cout << endl;

    return 0;
}


