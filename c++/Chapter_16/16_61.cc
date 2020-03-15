#include "Mymake_shared.h"

int main()
{
    std::shared_ptr<int> p = make_shared<int>(1);
    std::cout << *p << std::endl;

    return 0;
}
