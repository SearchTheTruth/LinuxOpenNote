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
    vector<int> myvec;
    myvec.reserve(5);
    for (int i = 0; i < 6; i++)
        myvec.push_back(i);
    print(myvec);
    cout << "capacity = " << myvec.capacity() << " size = " << myvec.size() << endl;
    for (int i = 0; i < 6; i++)
        myvec.push_back(i);
    print(myvec);
    cout << "capacity = " << myvec.capacity() << " size = " << myvec.size() << endl;
    return 0;
}
