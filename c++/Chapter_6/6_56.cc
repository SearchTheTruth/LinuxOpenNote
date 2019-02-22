#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int add(int a, int b);


typedef int (*type_p)(int, int);//这三条函数指针类型的定义等价
typedef decltype(add) *type_decl_p;
using using_p = int (*)(int, int);


int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int dev(int a, int b)
{
    return a / b;
}


int main()
{
    vector<using_p> func_p;

    func_p.push_back(add);
    func_p.push_back(sub);
    func_p.push_back(mul);
    func_p.push_back(dev);


    for (auto &p : func_p) {
        cout << p(10, 2) << endl;
    }
    return 0;
}

