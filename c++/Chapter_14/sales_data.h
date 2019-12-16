#ifndef _SALES_DATA_H
#define _SALES_DATA_H
#include <string>
#include <iostream>

struct sales_data {
friend std::ostream &print(std::ostream &os, const struct sales_data &book);
friend sales_data operator+(const sales_data&, const sales_data&);
friend std::istream& operator>>(std::istream &is, sales_data &org);
friend std::ostream& operator<<(std::ostream &os, const sales_data& org);

public:
    sales_data() = default;
    sales_data(const std::string &name): bookNo(name) {};
    sales_data(const std::string &name, unsigned num, double unitprice):
        bookNo(name), units_sold(num), revenue(unitprice * units_sold) {};
    sales_data(std::istream &is) {is >> bookNo >> units_sold >> revenue;};
    sales_data& operator+=(const sales_data&);
    sales_data& operator=(const std::string &str);
    operator double() const { return avg_prices(); };
    explicit operator std::string() const { return bookNo; };

    std::string isbn() const {return bookNo;};
    struct sales_data &combine (const struct sales_data &sec);
    double avg_prices() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

sales_data& sales_data::operator=(const std::string &str)
{
    bookNo = str;
    return *this;
}

sales_data operator+(const sales_data &l, const sales_data &r)
{
    sales_data tmp = l;
    tmp += r;
    return tmp;
}

sales_data& sales_data::operator+=(const sales_data &org)
{
    units_sold += org.units_sold;
    revenue += org.revenue;
    return *this;
}

std::istream& operator>>(std::istream &is, sales_data &org)
{
    double price = 0;
    is >> org.bookNo >> org.units_sold >> price;
    if (is)
        org.revenue = org.units_sold * price;
    else
        org = sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const sales_data &org)
{
    os << org.bookNo << " " << org.units_sold << " " << org.revenue << " " << org.avg_prices();
    return os;
}

inline std::ostream &print(std::ostream &os, const struct sales_data &book)
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
