#include <string>
#include <iostream>
#include "Quote.h"
#include "Limit_quote.h"

using namespace std;

void print_total(ostream &os, Quote &item, size_t n)
{
    os << item.isbn() << " sold #" << n << " total price is " << item.net_price(n) << endl;
}

int main()
{
    Quote base("good", 10);
    Limit_quote limit("limit", 10, 10, 0.3);
    print_total(cout, limit, 10);
    print_total(cout, limit, 11);
    return 0;
}
