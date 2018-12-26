#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item totalItem, currentItem;

    if (std::cin >> totalItem) {
        while (std::cin >> currentItem) {
            if(currentItem.isbn() == totalItem.isbn()) {
                totalItem += currentItem;
            } else {
                std::cout << totalItem << std::endl;
                totalItem = currentItem;
            }
        }
        std::cout << totalItem << std::endl;
    }

    return 0;
}
