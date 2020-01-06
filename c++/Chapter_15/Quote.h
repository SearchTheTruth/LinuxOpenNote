#ifndef __QUOTE_H
#define __QUOTE_H

#include <string>
#include <iostream>

class Quote {
    public:
        Quote() = default;
        Quote(std::string name, double prc) : bookNo(name), price(prc) {};
        virtual double net_price(size_t n) const {
            //std::cout << "Quote" << std::endl;
            return n * price;
        };
        virtual void debug() const {
            std::cout << "class Quote::" << std::endl;
            std::cout << "  " << "bookNo: " << bookNo << std::endl;
            std::cout << "  " << "price: " << price << std::endl;
        };
        Quote(const Quote &org) {
            std::cout << "Quote(const Quote &org)" << std::endl;
            bookNo = org.bookNo;
            price = org.price;
        };
        Quote(Quote &&org) = default;
        Quote& operator=(const Quote &org) {
            std::cout << "Quote& operator=(const Quote &org)" << std::endl;
            bookNo = org.bookNo;
            price = org.price;
            return *this;
        }
        Quote& operator=(Quote &&org) {
            std::cout << "Quote& operator=(Quote &&org)" << std::endl;
            bookNo = org.bookNo;
            price = org.price;
            return *this;
        }
        virtual ~Quote() = default;
        virtual Quote* clone() const &;
        virtual Quote* clone() &&;
        std::string isbn() { return bookNo; };
    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

Quote* Quote::clone() const & {
    return new Quote(*this);
}

Quote* Quote::clone() && {
    return new Quote(std::move(*this));
}
#endif
