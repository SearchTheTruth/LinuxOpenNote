#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

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
    list<const char *> list_char {"hello", "world"};
    print(list_char);
    vector<string> vec_str {"destory", "earth"};
    print(vec_str);

    cout << "after assgin" << endl;

    vec_str.assign(list_char.begin(), list_char.end());
    print(list_char);
    print(vec_str);
    return 0;
}
