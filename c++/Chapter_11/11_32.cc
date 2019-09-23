#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> author;
    author.insert({"jiang", "book1"});
    author.insert({"jiang", "book2"});
    author.insert({"jiang", "book3"});
    author.insert({"jiang", "book4"});
    author.insert({"Gaoo" , "picture1"});

//1th
    auto pos = author.find("jiang");
    int count = author.count("jiang");

    for (int i = 0; i < count; ++i, ++pos) {
        cout << pos->first << " " << pos->second << endl;
    }
    cout << "===========" << endl;

//2th
    for (auto p = author.lower_bound("jiang");
            p != author.upper_bound("jiang"); ++p) {
        cout << p->first << " " << p->second << endl;
    }
    cout << "===========" << endl;

//3th
    for (auto p = author.equal_range("jiang");
            p.first != p.second; ++p.first) {
        cout << p.first->first << " " << p.first->second << endl;
    }
    cout << "===========" << endl;

    return 0;
}
