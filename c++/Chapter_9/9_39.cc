#include <vector>
using std::vector;

#include <string>
using std::string;

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
    vector<string> myvec;
    myvec.reserve(1024);
    string word;
    while (cin >> word)
        myvec.push_back(word);
    print(myvec);
    cout << "capacity = " << myvec.capacity() << " size = " << myvec.size() << endl;
    myvec.resize(myvec.size() + myvec.size()/2, "init");
    print(myvec);
    cout << "capacity = " << myvec.capacity() << " size = " << myvec.size() << endl;
    return 0;
}
