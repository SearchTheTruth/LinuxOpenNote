#ifndef __BASKET_H
#define __BASKET_H

#include <set>
#include <memory>
#include <iostream>
#include "Quote.h"

using namespace std;

int print_total(ostream &os, Quote &item, size_t n)
{
    double price = 0;
    os << item.isbn() << " sold #" << n << " price is " << (price = item.net_price(n)) << endl;
    return price;
}

class Basket {
    public:
        void add_item(const Quote &item);
        void add_item(Quote &&item);
        int total_price(ostream &os);
        void add_item(const shared_ptr<Quote> &sale) {
            items.insert(sale);
        }
    private:
        static bool compare(const shared_ptr<Quote> &l, const shared_ptr<Quote> &r) {
            return l->isbn() < r->isbn();
        }
        multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

void Basket::add_item(const Quote &item) {
    items.insert(shared_ptr<Quote>(item.clone()));
}

void Basket::add_item(Quote &&item) {
    items.insert(shared_ptr<Quote>(std::move(item).clone()));
}

int Basket::total_price(ostream &os) {
    int sum = 0;
    for (auto iter = items.cbegin();
            iter != items.cend();
            iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
    }
    return sum;
}
#endif
