#include <list>
using std::list;

#include <deque>
using std::deque;

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
    vector<int> svec {7, 1, 2, 3, 4};
    auto p0 = svec.begin();
    auto p1 = p0+1;
    auto p2 = p1+1;
    auto p3 = p2+1;
    auto p4 = p3+1;

    auto &beg = p0;
    auto &end = p4;

    auto &tmp1 = p1;

    cout << "p0 = " << *p0 << endl;
    cout << "p1 = " << *p1 << endl;
    cout << "p2 = " << *p2 << endl;
    cout << "p3 = " << *p3 << endl;
    cout << "p4 = " << *p4 << endl;
    print(svec);

    cout << "tmp1 = " << *tmp1 << " p1 = " << *p1 << endl;
    tmp1 = svec.erase(tmp1, p1);
    cout << "tmp1 = " << *tmp1 << " p1 = " << *p1 << endl;
    print(svec);

    auto tmp2 = svec.end();
    auto tmp3 = svec.end();
    cout << "tmp2 = " << *tmp2 << " tmp3 = " << *tmp3 << endl;
    tmp3 = svec.erase(tmp2, tmp3);
    cout << "tmp2 = " << *tmp2 << " tmp3 = " << *tmp3 << endl;
    print(svec);


    return 0;
}

