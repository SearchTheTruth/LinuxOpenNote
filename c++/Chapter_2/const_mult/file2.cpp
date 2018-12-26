#include <iostream>


/*
 * four variable all first definition here.
 */
extern int normalVar;
extern int extnormalVar;
const int constVar = 72;
extern const int extconstVar;

int file2()
{
    std::cout << "file2: " << normalVar << extnormalVar << constVar << extconstVar\
        << std::endl;

    return 0;
}
