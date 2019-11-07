#ifndef __HASPTR_H
#define __HASPTR_H

#include <string>
#include <iostream>
#include <memory>

class HasPtr {
    public:
    ~HasPtr() {
        std::cout << "release" << std::endl;
        if (--*refs_cnt == 0) {
            delete ps;
            delete refs_cnt;
        }
    }

    HasPtr& operator=(const HasPtr& org) {
        std::cout << "=" << std::endl;
        if (--*refs_cnt == 0) {
            delete ps;
            delete refs_cnt;
        }
        ps = org.ps;
        i = org.i;
        refs_cnt = org.refs_cnt;
        ++*refs_cnt;
        return *this;
    }

    void print() {
        std::cout << ps << ": " << *ps << std::endl;
    }

    HasPtr(const std::string &s) : ps(new std::string(s)), refs_cnt(new int(1)), i(0) { std::cout << "init" << std::endl; };
    HasPtr(const HasPtr &org) : ps(org.ps), refs_cnt(org.refs_cnt), i(org.i) { std::cout << "copy" << std::endl; ++*refs_cnt; };
    private:
        std::string *ps;
        int *refs_cnt;
        int i;
};
#endif
