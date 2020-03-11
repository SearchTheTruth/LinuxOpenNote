#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void turn_around(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void func(int &i, int &&j)
{
    std::cout << i << std::endl;
    std::cout << j << std::endl;
}

int main()
{
    int a = 1;

    //turn_around(func, a, 2);          反转后, func调用时尝试执行int &i = 2,只有const int&可以绑定到常量上
    std::cout << "===" << std::endl;
    turn_around(func, 2, a);

    return 0;
}
