#include "sales_data.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    sales_data tmp("goodbook", 10, 100);
    string bookNo = static_cast<string>(tmp);
    double unitprice = tmp;
    cout << bookNo << ": " << unitprice << endl;
    return 0;
}
