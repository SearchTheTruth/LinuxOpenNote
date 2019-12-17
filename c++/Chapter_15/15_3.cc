#include <iostream>
#include <string>
#include "Quote.h"

using namespace std;

void print_total(ostream &os, Quote &item, size_t n)
{
    os << item.isbn() << " sold #" << n << " total price is " << item.net_price(n) << endl;
}

int main()
{
    Quote mybook("nice", 10);
    print_total(cout, mybook, 7);
    return 0;
}
