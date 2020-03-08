#include "Myshared_ptr.h"

template <typename T> void Myshared_ptr<T>::destory_sp(Myshared_ptr &sp)
{
    if (sp.count) {
        --(*sp.count);
        if (*sp.count == 0) {
            sp.del ? del(sp.sp) : delete sp.sp;
            delete sp.count;
            sp.sp = nullptr;
            sp.count = nullptr;
            sp.del = nullptr;
        }
    }
}
