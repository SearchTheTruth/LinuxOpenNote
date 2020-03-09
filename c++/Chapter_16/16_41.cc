#include <iostream>


template <typename T>
auto sum(T l, T h) -> decltype(l + h)
{
    return l + h;
}

int main()
{
    unsigned char max = 255;
    unsigned char one = 1;
    unsigned char two = 2;
    unsigned char ret = max + one;
    unsigned char ret2 = max + two;

    std::cout << "sum = " << sum(max, one) << " " << "ret = " << ret << std::endl;
    std::cout << "ret2 = " << ret2 << std::endl;
    return 0;
}
