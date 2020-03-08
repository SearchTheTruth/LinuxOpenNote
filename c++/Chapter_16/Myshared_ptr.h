#ifndef _MYSHARED_PTR_H
#define _MYSHARED_PTR_H

#include <memory>
#include <functional>

using namespace std;

template <typename T> class Myshared_ptr
{
    public:
        Myshared_ptr() : count(nullptr), sp(nullptr), del(nullptr) {};
        Myshared_ptr(T *p) : count(new int(1)), sp(p), del(nullptr) {};
        Myshared_ptr(T *p, function<void(T*)> func) : count(new int(1)), sp(p), del(func) {};
        Myshared_ptr(const Myshared_ptr &org) {
            if (org.count != count) {
                destory_sp(*this);
                sp = org.sp;
                del = org.del;
                count = org.count;
                ++(*count);
            }
        };
        Myshared_ptr& operator=(Myshared_ptr &org)
        {
            if (org.count != count) {
                destory_sp(*this);
                sp = org.sp;
                del = org.del;
                count = org.count;
                ++(*count);
            }
            return *this;
        };
        T& operator*() const {
            return *sp;
        }
        T* operator->() const {
            return & this->operator*();
        }
        ~Myshared_ptr() {
            destory_sp(*this);
        };
        void reset(T *p) {
            destory_sp(*this);
            *this = Myshared_ptr(p);
        };
        void reset(T *p, function<void(T*)> func) {
            destory_sp(*this);
            *this = Myshared_ptr(p, func);
        };
    private:
        void destory_sp(Myshared_ptr &sp);
        int *count;
        T *sp;
        function<void(T*)> del;
};

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
#endif
