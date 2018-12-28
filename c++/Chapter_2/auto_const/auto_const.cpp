#include <iostream>

int main()
{
    const int cstint = 100;
    auto &ref = cstint;

    std::cout << cstint << " " << ref << std::endl;

    ref += 1;

    //auto &cstref = 90; error
    const auto &cstref = 90;
}
