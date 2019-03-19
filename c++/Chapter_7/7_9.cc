#include "person.h"


std::istream &read(std::istream &is, struct person &per)
{
    is >> per.name >> per.addr;
    return is;
}

std::ostream &print(std::ostream &os, const struct person &per)
{
    os << per.isName() << " is live in " << per.isAddr();
    return os;
}

int main()
{
    struct person tom;

    read(std::cin, tom);
    print(std::cout, tom);

    return 0;
}
