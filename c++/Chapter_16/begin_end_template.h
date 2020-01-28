#ifndef __BEGIN_END_TEMPLATE_H
#define __BEGIN_END_TEMPLATE_H

template <typename T, unsigned N> T *begin(const T (&arr)[N])
{
    return &arr[0];
}

template <typename T, unsigned N> T *end(const T (&arr)[N])
{
    return ++(&arr[N]);
}

#endif
