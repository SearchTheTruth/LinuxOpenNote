#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iterator>
using std::begin;
using std::end;

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
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> odd(begin(ia), end(ia));
    list<int> even(begin(ia), end(ia));

    for (auto pos = odd.begin(); pos != odd.end(); ) {
        if (*pos & 0x1)
            ++pos;
        else
            pos = odd.erase(pos);
    }

    for (auto pos = even.begin(); pos != even.end(); ) {
        if (*pos& 0x1)
            pos = even.erase(pos);
        else
            ++pos;
    }

    cout << "odd" << endl;
    print(odd);
    cout << endl;

    cout << "even" << endl;
    print(even);
    cout << endl;

    return 0;
}
