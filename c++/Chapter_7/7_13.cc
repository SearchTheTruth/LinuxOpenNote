#include "sales_data.h"

using std::cin;
using std::cout;
using std::endl;

struct sales_data &sales_data::combine(const struct sales_data &sec)
{
    units_sold += sec.units_sold;
    revenue += sec.revenue;

    return *this;
}

int main()
{
    struct sales_data total(cin);
    if (!total.isbn().empty()) {
        while (cin) {
            struct sales_data trans(cin);
            if (trans.isbn().empty() || !cin) {
                break;
            } else if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cout << "no data or other err\n";
    }
    return 0;
}
