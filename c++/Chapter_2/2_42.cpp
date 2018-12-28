#include <iostream>
#include <string>
#include "2_40.h"//My_SalesData

int main()
{
    struct My_SalesData item1, item2;

    std::cin >> item1.bookNo >> item1.saledNum >> item1.price;
    std::cin >> item2.bookNo >> item2.saledNum >> item2.price;

    if (item1.bookNo == item2.bookNo) {
        struct My_SalesData itemSum;
        std::cout << "The book number are samed" << std::endl;
        itemSum.bookNo = item1.bookNo;
        itemSum.saledNum = item1.saledNum + item2.saledNum;
        itemSum.total = (item1.saledNum * item1.price) + (item2.saledNum * item2.price);
        itemSum.price = itemSum.total / itemSum.saledNum;
        std::cout << itemSum.bookNo << " " << itemSum.total << " " << itemSum.saledNum << " " << itemSum.price << std::endl;
    } else {
        std::cout << "The book number are different" << std::endl;
        std::cout << item1.bookNo << " " << item1.saledNum << " " << item1.price << std::endl;
        std::cout << item2.bookNo << " " << item2.saledNum << " " << item2.price << std::endl;
    }

    return 0;
}

