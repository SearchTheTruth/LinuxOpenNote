#ifndef __LIMIT_QUOTE_H
#define __LIMIT_QUOTE_H

#include "Quote.h"

class Limit_quote : public Quote {
    public:
        Limit_quote(const Quote &base, size_t min, size_t max, double off) :\
            Quote(base), min_qty(min), max_qty(max), discount(off) {};
        double net_price(size_t n) const override {
            if (n < min_qty) {
                return n * price;
            } else if (n >= min_qty && n <= max_qty) {
                return n * (1 - discount) * price;
            } else {
                return (n - max_qty) * price + max_qty * (1 - discount) * price;
            }
        };
    private:
        size_t min_qty;
        size_t max_qty;
        double discount;
};

#endif
