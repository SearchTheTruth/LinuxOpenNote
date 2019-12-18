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
        Quote(const Quote &org) {
            std::cout << "Quote(const Quote &org)" << std::endl;
            bookNo = org.bookNo;
            price = org.price;
        };
        Quote& operator=(const Quote &org) {
            std::cout << "Quote& operator=(const Quote &org)" << std::endl;
            bookNo = org.bookNo;
            price = org.price;
            return *this;
        }
        virtual ~Quote() = default;
        std::string isbn() { return bookNo; };
    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

#endif
