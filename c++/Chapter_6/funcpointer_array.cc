#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::begin;
using std::end;



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
    type_decl_p p_arr[4] = {add, sub, mul, dev};

    for (auto i = begin(p_arr); i != end(p_arr); i++)
        cout << (*i)(10, 2) << endl;

    for (int i = 0; i < 4; i++)
        cout << p_arr[i](10, 2) << endl;

    return 0;
}

