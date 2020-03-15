#include "StrVec.h"
#include <iostream>

int main()
{
    StrVec tmp;
    std::string dog("dog");
    tmp = {"hello", "world"};
    tmp.emplace_back("good");
    tmp.emplace_back(std::move(dog));
    std::cout << tmp << std::endl;
    return 0;
}
