#include "Quote.h"
#include "Bulk_quote.h"

int main()
{
    Quote base("base", 10);
    Bulk_quote derived("derived", 10, 5, 0.2);

    base.debug();
    std::cout << "===" << std::endl;
    derived.debug();
}
