#include "Bulk_quote.h"
#include <vector>
#include <memory>

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> spQuote;

    spQuote.push_back(make_shared<Quote>("quo", 10));
    spQuote.push_back(make_shared<Bulk_quote>("bulk", 10, 10, 0.3));

    double total = 0;
    for(const auto &ele : spQuote) {
        total += ele->net_price(10);
    }
    cout << total << endl;
    return 0;
}
