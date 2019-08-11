#include <list>
using std::list;

#include <deque>
using std::deque;

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
    string word;
    list<string> ilist;
    while (cin >> word) {
        ilist.push_back(word);
    }

    print(ilist);
    return 0;
}
