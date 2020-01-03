#include "Bulk_quote.h"

int main()
{
    Bulk_quote org("orgBook", 10, 10, 0.3);
    Bulk_quote copy;
    copy = org;
    return 0;
}
