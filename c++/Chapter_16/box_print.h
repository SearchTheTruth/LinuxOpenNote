#ifndef __BOX_PRINT_H
#define __BOX_PRINT_H

#include <iostream>

template <typename T> void box_print(const T &box)
{
    typename T::size_type pos = 0;
    while (pos < box.size()) {
        std::cout << box[pos++] << " ";
    }
    std::cout << std::endl;
}

template <typename I> void box_print(I beg, I end)
{
    while (beg != end) {
        std::cout << *(beg++) << " ";
    }
    std::cout << std::endl;
}

#endif
