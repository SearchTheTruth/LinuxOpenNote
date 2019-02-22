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

typedef type_p pointer_arr[4];

type_p g_arr[4];

pointer_arr *stuff()
{
    g_arr[0] = add;
    g_arr[1] = sub;
    g_arr[2] = mul;
    g_arr[3] = dev;

    return g_arr;
}

int main()
{
    pointer_arr pp = stuff;

    for (int i = 0; i < 4; i++)
        cout << pp[i](10, 2) << endl;

    return 0;
}

