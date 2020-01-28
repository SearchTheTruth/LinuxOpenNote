#ifndef __FIND_TEMPLATE_H
#define __FIND_TEMPLATE_H

template <typename ITERATOR, typename T> ITERATOR find(ITERATOR beg, ITERATOR end, const T &dest)
{
    while (beg != end) {
        if (*beg == dest)
            return beg;
        else
            beg++;
    }
    return end;
}

#endif
