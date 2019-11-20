#include "MyString.h"
#include <iostream>

int main()
{
    Mystring hello("HelloWorld");
    std::cout << hello.get_str();
    return 0;
}

