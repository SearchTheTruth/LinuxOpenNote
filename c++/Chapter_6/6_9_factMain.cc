#include <iostream>
#include "Chapter6.h"


int main()
{
    int num;

    if (std::cin >> num) {
        std::cout << num << "! = " << fact(num) << std::endl;
    }
}
