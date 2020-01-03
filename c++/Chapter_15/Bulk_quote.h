#ifndef __BULK_QUOTE_H
#define __BULK_QUOTE_H
#include <string>
#include <iostream>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(std::string name, double prc, size_t num, double rate) :\
            Disc_quote(name, prc, num, rate) {};
        Bulk_quote(const Bulk_quote &org) : Disc_quote(org) {
            std::cout << "Bulk_quote(const Bulk_quote &org)" << std::endl;
        };
        Bulk_quote& operator=(const Bulk_quote &org) {
            std::cout << "Bulk_quote& operator=" << std::endl;
            Disc_quote::operator=(org);
        };
        ~Bulk_quote() override = default;
        double net_price(size_t n) const override {
            //std::cout << "Bulk_quote" << std::endl;
            if (n >= quantity) {
                return n * (1 - discount) * price;
            } else {
                return n * price;
            }
        };
        void debug() const override {
            Disc_quote::debug();
            std::cout << "class Bulk_quote::" << std::endl;
        };
};
#endif
