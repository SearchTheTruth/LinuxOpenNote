#ifndef __BULK_QUOTE_H
#define __BULK_QUOTE_H
#include <string>
#include "Quote.h"
#include <iostream>

class Bulk_quote : public Quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(std::string name, double prc, size_t num, double rate) :\
            Quote(name, prc), min_qty(num), discount(rate) {};
        double net_price(size_t n) const override {
            //std::cout << "Bulk_quote" << std::endl;
            if (n >= min_qty) {
                return n * (1 - discount) * price;
            } else {
                return n * price;
            }
        };
    private:
        size_t min_qty;
        double discount;
};
#endif
