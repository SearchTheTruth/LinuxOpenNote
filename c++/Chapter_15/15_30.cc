#include "Basket.h"
#include "Bulk_quote.h"
#include "Quote.h"

int main()
{
    Basket box;
    box.add_item(Quote("q1", 10));
    box.add_item(Quote("q1", 10));
    box.add_item(Quote("q2", 5));

    for (int i = 0; i < 10; ++i) {
        box.add_item(Bulk_quote("b1", 10, 5, 0.3));
    }
    box.add_item(Bulk_quote("b2", 100, 2, 0.6));

    double price = box.total_price(cout);
    cout << "total_price = " << price << endl;
    return 0;
}
