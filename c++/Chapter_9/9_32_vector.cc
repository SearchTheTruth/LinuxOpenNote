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
    vector<int> myvec {0, 1, 2, 3, 4, 5, 6, 7, 9};
    print(myvec);
    auto cur = myvec.begin();
    while (cur != myvec.end()) {
        if (*cur & 0x1 == 0x1) {
            cur = myvec.insert(cur, *cur++);
            ++cur;
        } else {
            cur = myvec.erase(cur);
        }
    }
    print(myvec);
    return 0;
}
