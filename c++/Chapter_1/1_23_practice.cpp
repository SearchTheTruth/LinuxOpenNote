#include <iostream>
#include "Sales_item.h"

int main()
{
    int counter = 0;
    Sales_item currentItem, totalItem;

    if (std::cin >> totalItem)
    {
        counter = 1;

        while (std::cin >> currentItem)
        {
            if (currentItem.isbn() == totalItem.isbn())
            {
                ++counter;
            }
            else
            {
                std::cout << totalItem.isbn() <<": "<< counter << std::endl;
                totalItem = currentItem;
                counter = 1;
            }
        }
        std::cout << totalItem.isbn() <<": "<< counter << std::endl;
    }
    return 0;
}
