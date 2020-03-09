#include <iostream>
#include <vector>

template <typename T> void g1(T val)
{
    return ;
}

template <typename T> void g2(T&& val)
{
    std::vector<T> v;
}

int main()
{
    int i = 0;
    const int ci = i;

    g1(i * ci); //T = int&&

    g2(42); //T =int
    //g2(i); //T = int& vector不支持
}
