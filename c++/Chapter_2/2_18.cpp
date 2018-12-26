#include <iostream>

int main()
{
    int num = 1;
    int *numPtr = &num;

    std::cout << "num = " << num << "\t" << "numPtr = " << numPtr << std::endl;

    *numPtr = 33;
    numPtr = nullptr;

    std::cout << "num = " << num << "\t" << "numPtr = " << numPtr << std::endl;

    return 0;
}
