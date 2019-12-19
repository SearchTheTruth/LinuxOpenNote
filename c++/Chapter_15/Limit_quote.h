#ifndef __LIMIT_QUOTE_H
#define __LIMIT_QUOTE_H

#include "Disc_quote.h"

using namespace std;

class Limit_quote : public Disc_quote {
    public:
        Limit_quote(string name, double prc, size_t n, double off) :\
            Disc_quote(name, prc, n, off) {};
        double net_price(size_t n) const override {
            return n * price * (n > quantity ? 1 : 1 - discount);
        };
};

#endif
