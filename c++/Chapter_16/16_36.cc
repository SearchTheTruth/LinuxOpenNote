#include <iostream>

template <typename T> void f1(T, T)
{
    std::cout << "f1()" << std::endl;
}

int main()
{
    int i = 7, *p = &i;
    const int *cp = &i;

    f1(p, cp);

    return 0;
}
