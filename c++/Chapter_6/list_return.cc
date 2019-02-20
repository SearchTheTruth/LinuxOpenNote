#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<string> processStr(const string &a, const string &b)
{
    if (a == b)
        return {};    //默认初始化即类型定义的初始化
    else
        return {"processStr", a, b};
}

int processInt(const int &i, const int &j)
{
    if (i == j)
        return {};   //值初始化
    else
        return {i};  //内置类型只能返回一个值
}

int main()
{
    int num;
    vector<string> ret;

    ret = processStr("hello", "hello");

    for (auto &i : ret)
        cout << i << " ";
    cout << endl;

    ret = processStr("hello", "world");

    for (auto &i : ret)
        cout << i << " ";
    cout << endl;

    num = processInt(1, 1);
        cout << num << endl;

    num = processInt(1, 2);
        cout << num << endl;

    return 0;
}
