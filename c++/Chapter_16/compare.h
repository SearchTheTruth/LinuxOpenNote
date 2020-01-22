#ifndef __COMPARE_H
#define __COMPARE_H

//left < right return 1
//right < left return -1
//left = right return 0

template <typename T> int compare(const T &l, const T &r)
{
    if (l < r)
        return 1;
    if (r < l)
        return -1;
    return 0;
}

#endif
