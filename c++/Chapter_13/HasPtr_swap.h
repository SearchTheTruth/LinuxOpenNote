#ifndef __HASPTR_H
#define __HASPTR_H

#include <string>
#include <iostream>
#include <memory>

class HasPtr {
    public:
    friend void swap(HasPtr &l, HasPtr &r);
    friend bool operator<(const HasPtr &l, const HasPtr &r);

    HasPtr& operator=(const HasPtr& org) {
        std::cout << "operator=" << *ps << " = " << *org.ps << std::endl;
        auto copy = new std::string(*(org.ps));
        if (ps)
            delete ps;
        ps = copy;
        i = org.i;
        return *this;
    }
#if 0
    bool operator<(const HasPtr& org) {
        std::cout << "<(const HasPtr& org)" << std::endl;
        return *ps < *org.ps;
    }
#endif

    void swap(HasPtr &org) {
        using std::swap;
        std::cout << "swap(HasPtr &org)" << std::endl;
        swap(ps, org.ps);
        swap(i, org.i);
    }

    void print() {
        std::cout << ps << ": " << *ps << std::endl;
    }

    HasPtr() : ps(nullptr), i(0) {};
    HasPtr(const std::string &s) : ps(new std::string(s)), i(0) {};
    HasPtr(const HasPtr &org) : ps(new std::string(*(org.ps))), i(org.i) {};
    ~HasPtr() {
        delete ps;
    }
    private:
        std::string *ps;
        int i;
};

inline void swap(HasPtr &l, HasPtr &r)
{
    std::cout << "swap(HasPtr &l, HasPtr &r)" << std::endl;
    l.swap(r);
}

bool operator<(const HasPtr &l, const HasPtr &r) {
    std::cout << "<(const HasPtr &l, const HasPtr &r)" << std::endl;
    return *l.ps < *r.ps;
}
#endif
