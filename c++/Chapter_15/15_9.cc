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
    Bulk_quote bulk("bulk", 10, 5, 0.2);

//1.引用
    Quote &ref_qut = bulk;
    print_total(cout, ref_qut, 10);

//2.指针
    Quote *ptr_qut = &bulk;
    print_total(cout, *ptr_qut, 10);


//3.拷贝构造函数(本质还是引用)
    Quote eq_qut = bulk;
    print_total(cout, eq_qut, 10);

    return 0;
}
