#include "sales_data.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct sales_data &sales_data::combine(const struct sales_data &sec)
{
    units_sold += sec.units_sold;
    revenue += sec.revenue;

    return *this;
}

int main()
{
   struct sales_data data1 = {"0x1First", 2, 10.0};
   struct sales_data data2 = {"0x1First", 3, 15.0};

    cout << "data1 bookNo[" << data1.isbn() << "]" << endl;
    cout << "data2 bookNo[" << data2.isbn() << "]" << endl;

    data1.combine(data2);

    cout << "data1 units_sold = " << data1.units_sold << endl;
    cout << "data1 revenue = " << data1.revenue << endl;

    return 0;
}
