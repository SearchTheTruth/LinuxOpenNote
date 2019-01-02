#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> str;
    string word;

    while (cin >> word) {
        str.push_back(word);
    }

    for (auto &str_one : str) {     //此处若不使用引用则最终结果不会改变.
        for (auto &word_one : str_one)
            word_one = toupper(word_one);
        cout << str_one << endl;
    }

    for (auto str_one : str)
        cout << str_one << endl;

    return 0;
}

/*
 * 若line20 没有使用引用，则此时string str_one是vector<string> str[x]的一个副本。
 * line22修改的实际上是该副本的内容，不会改变str中的内容
 * 若line20使用引用，则此时str one表示的是str中某个元素的别名。
 * line22的修改最终修改的是str中的每个元素str[x]。
 * */
