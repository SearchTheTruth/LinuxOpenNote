#ifndef _SALES_DATA_H
#define _SALES_DATA_H
#include <string>
struct sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
    std::string isbn() const {return bookNo;};
    struct sales_data &combine (const struct sales_data &sec);
};

#endif
