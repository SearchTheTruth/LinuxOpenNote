#include "sales_data.h"


using std::cout;
using std::cin;
using std::endl;

sales_data::sales_data(std::istream &is)
{
    is >> bookNo >> units_sold >> revenue;
}

int main()
{
    struct sales_data def;
    struct sales_data name("name");
    struct sales_data total("total", 3, 15.0);
    cout << "please input book name, units sold, revenue" << endl;
    struct sales_data input(cin);

    print(cout, def);
    cout << endl;
    print(cout, name);
    cout << endl;
    print(cout, total);
    cout << endl;
    print(cout, input);
    cout << endl;

    return 0;
}
