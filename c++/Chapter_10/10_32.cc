#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include "Sales_item.h"

using namespace std;

bool compareIsbn_1(const Sales_item &bk1, const Sales_item &bk2)
{
    return bk1.isbn() < bk2.isbn();
}

int main()
{
    cout << "Start" << endl;
    istream_iterator<Sales_item> is(cin), eof;
    vector<Sales_item> saleBooks;

    while (is != eof)
        saleBooks.push_back(*is++);
    sort(saleBooks.begin(), saleBooks.end(), compareIsbn_1);

    auto beg = saleBooks.begin();
    auto last_beg = beg;
    while (beg != saleBooks.end()) {
        beg = find_if(beg, saleBooks.end(), [=](const Sales_item &cur) {return cur.isbn() != beg->isbn();});
        auto result = accumulate(last_beg, beg, Sales_item(last_beg->isbn()));
        cout << result.isbn() << ": " << result.istotal() << endl;
        last_beg = beg;
    }
    return 0;
}
