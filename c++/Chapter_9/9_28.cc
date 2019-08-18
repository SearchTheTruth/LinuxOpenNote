#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <forward_list>
using std::forward_list;

#include <string>
using std::string;

void print(const auto &src)
{
    for (auto beg = src.begin(); beg != src.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

forward_list<string> &insert_string(forward_list<string>&src, const string &search, const string &add)
{
    forward_list<string>::iterator pos;
    auto cur = src.begin();

    while (cur != src.end()) {
        if (*cur == search) {
            pos = cur;
            break;
        } else {
            pos = cur;
            ++cur;
        }
    }
    src.insert_after(pos, add);
}

int main()
{
    forward_list<string> flist {"Hello", "World", "!!"};
    print(flist);

    insert_string(flist, "Hello", "Wondeful");
    print(flist);

    insert_string(flist, "xxx", "I'm tired");
    print(flist);
    return 0;
}
