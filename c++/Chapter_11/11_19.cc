#include <set>
#include <string>
#include <list>
#include <iostream>
#include "sales_data.h"

using namespace std;

bool compareIsbn(const sales_data &l, const sales_data &r)
{
    return l.isbn() < r.isbn();
}

typedef bool (*comparePtr) (const sales_data &, const sales_data &);

int main()
{
    multiset <sales_data, comparePtr> bookstore(compareIsbn);
    multiset <sales_data, comparePtr>::iterator it = bookstore.begin();
    return 0;
}
