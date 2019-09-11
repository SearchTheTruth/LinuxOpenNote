#include <list>
#include <string>
#include <iostream>

using namespace std;


int main()
{
    list<string> tmp{"hello", "my", "world", "the", "and", "but", "open", "and", "there", "apple", "my", "mouth"};
    tmp.sort();
    cout << "sort" << endl;
    for (auto ch : tmp)
        cout << ch << " ";
    cout << endl;
    cout << "unique" << endl;
    tmp.unique();
    for (auto ch : tmp)
        cout << ch << " ";
    cout << endl;
}
