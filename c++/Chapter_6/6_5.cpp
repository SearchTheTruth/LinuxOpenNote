#include <iostream>

int mod(int val)
{
    return val >= 0 ? val : -val;
}

int main()
{
    int num;

    std::cout << "pls enter a digital\n";
    std::cin >> num;

    std::cout << "|" << num <<"| = " << mod(num) << std::endl;

    return 0;
}
