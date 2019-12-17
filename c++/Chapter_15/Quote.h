#ifndef __QUOTE_H
#define __QUOTE_H

#include <string>

class Quote {
    public:
        Quote() = default;
        Quote(std::string name, double prc) : bookNo(name), price(prc) {};
        virtual double net_price(size_t n) const {
            return n * price;
        };
        Quote(const Quote &org) {
            bookNo = org.bookNo;
            price = org.price;
        };
        virtual ~Quote() = default;
        std::string isbn() { return bookNo; };
    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

#endif
