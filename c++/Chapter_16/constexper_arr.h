#ifndef __CONSTEXPER_ARR_H
#define __CONSTEXPER_ARR_H

template <typename T, unsigned N> constexpr int arraysize(const T (&arr)[N])
{
    return N;
}

#endif
