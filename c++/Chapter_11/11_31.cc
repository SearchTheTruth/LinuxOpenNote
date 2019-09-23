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

    auto pos = author.find("jiang");
    author.erase(pos);
    for (auto pair : author) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << "=============" << endl;
    author.erase("jiang");
    for (auto pair : author) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
