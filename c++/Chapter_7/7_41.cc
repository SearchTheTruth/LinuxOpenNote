#include "delegate_sales_data.h"

int main()
{
    struct sales_data par_3("3_parameter", 3, 3);
    print(par_3);
    cout << "\n====================\n";

    struct sales_data par_str("1_str");
    print(par_str);
    cout << "\n====================\n";

    struct sales_data par_ept;
    print(par_ept);
    cout << "\n====================\n";

    cout << "input bookID, unitnum, prices\n";
    struct sales_data par_iostream(std::cin);
    print(par_iostream);
    cout << "\n====================\n";

    return 0;
}
