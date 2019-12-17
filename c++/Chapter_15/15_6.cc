#include <iostream>
#include <string>
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

void print_total(ostream &os, Quote &item, size_t n)
{
    os << item.isbn() << " sold #" << n << " total price is " << item.net_price(n) << endl;
}

int main()
{
    Quote mybook("nice", 10);
    Bulk_quote oldbook("old", 10, 10, 0.3);
    print_total(cout, mybook, 7);
    print_total(cout, oldbook, 5);
    print_total(cout, oldbook, 10);

    return 0;
}
