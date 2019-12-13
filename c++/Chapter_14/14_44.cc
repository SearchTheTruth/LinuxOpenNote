#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int multi(int l, int r)
{
    return l * r;
}

class divide {
    public:
        int operator()(int l, int r) {
            return l / r;
        }
};

map<string, function<int(int, int)>> calculator= {
    {"+", plus<int>()},                            //标准库定义的函数对象
    {"-", [](int l, int r)->int {return l - r;}},  //未命名lambda
    {"*", multi},                                  //函数指针
    {"/", divide()},                               //自定义的函数对象
};

int main()
{
    int l, r;
    string operand;

    while(cin >> l >> operand >> r) {
        cout << l << operand << r << "=" << calculator[operand](l, r) << endl;
    }
    return 0;
}
