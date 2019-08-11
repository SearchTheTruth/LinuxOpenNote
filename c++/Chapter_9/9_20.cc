#include <list>
using std::list;

#include <deque>
using std::deque;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const auto &src)
{
    cout << "event num =" << src.size() << "=" << endl;
    for (const auto &ev : src) {
        cout << ev << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    list<int> origin {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd_deq;
    deque<int> even_deq;

    for (const auto &ele : origin) {
        (ele & 0x1 ? odd_deq : even_deq).push_back(ele);
    }

    print(odd_deq);
    cout << endl;
    print(even_deq);

    return 0;
}



