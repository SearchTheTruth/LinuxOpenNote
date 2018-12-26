#include <iostream>


/*
 * four variable all first definition here.
 */
int normalVar = 1;
int extnormalVar = 1;
const int constVar = 2;
extern const int extconstVar = 2;

extern int file2();
int main()
{
    std::cout << "file1: " << normalVar << extnormalVar << constVar << extconstVar\
        << std::endl;

    file2();
    return 0;
}
