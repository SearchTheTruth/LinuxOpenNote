#ifndef _SALES_DATA_H
#define _SALES_DATA_H
#include <string>
#include <iostream>
using std::cout;

struct sales_data {
friend std::ostream &print(const struct sales_data &, std::ostream &);
public:
    sales_data(const std::string &name, unsigned num, double unitprice) :
        bookNo(name), units_sold(num), revenue(unitprice * units_sold) {cout << "use 3 parameter constructor\n";};
    sales_data() : sales_data("empty", 0, 0) {cout << "use 0 parameter constructor\n";};
    sales_data(const std::string &name) : sales_data("name", 0, 0) {cout << "use 1 string parameter constructor\n";};
    sales_data(std::istream &is) : sales_data() {is >> bookNo >> units_sold >> revenue;};

    std::string isbn() const {return bookNo;};
    struct sales_data &combine (const struct sales_data &sec);
    double avg_prices() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

inline std::ostream &print(const struct sales_data &book, std::ostream &os = cout)
{
    os << book.isbn() << " units: " << book.units_sold <<  " total: " << book.revenue << "$";
    return os;
}

inline double sales_data::avg_prices() const
{
    if (units_sold == 0)
        return 0;
    return revenue/units_sold;
}


#endif
