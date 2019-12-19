#ifndef __DISC_QUOTE_H
#define __DISC_QUOTE_H
#include "Quote.h"

using namespace std;
class Disc_quote : public Quote {
    public:
        Disc_quote() = default;
        Disc_quote(string name, double prc, size_t n, double off) :\
            Quote(name, prc), quantity(n), discount(off) {};
        double net_price(size_t n) const = 0;
        void debug() const override {
            std::cout << "class Disc_quote::" << std::endl;
            std::cout << "  " << "quantity: " << quantity << std::endl;
            std::cout << "  " << "discount: " << discount << std::endl;
        };
    protected:
        size_t quantity = 0;
        double discount = 0.0;
};

#endif
