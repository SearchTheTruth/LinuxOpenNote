#ifndef __HASPTR_H
#define __HASPTR_H

#include <string>
#include <iostream>
#include <memory>

class HasPtr {
    public:
    ~HasPtr() {
        delete ps;
    }

    HasPtr& operator=(const HasPtr& org) {
        if (!ps)
            delete ps;
        ps = new std::string(*(org.ps));
        i = org.i;
        return *this;
    }

    void print() {
        std::cout << ps << ": " << *ps << std::endl;
    }

    HasPtr() = default;
    HasPtr(const std::string &s) : ps(new std::string(s)), i(0) {};
    HasPtr(const HasPtr &org) : ps(new std::string(*(org.ps))), i(org.i) {};
    private:
        std::string *ps;
        int i;
};
#endif
