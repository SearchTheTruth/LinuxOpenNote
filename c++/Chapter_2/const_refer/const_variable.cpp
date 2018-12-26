#include <iostream>

int main()
{
    int num = 7;
    const int &cstRfer = num;
    int &refer = num;
    double numDouble = 3.14;
    const int &cstRferDouble = numDouble;

    std::cout << "num = " << num << " cstRfer = " << cstRfer\
        << " refer = " << refer << " cstRferDouble = " << cstRferDouble << std::endl;

    refer = 77;
    numDouble = 7.777;
    std::cout << "num = " << num << " cstRfer = " << cstRfer\
        << " refer = " << refer << " cstRferDouble = " << cstRferDouble << std::endl;
}
