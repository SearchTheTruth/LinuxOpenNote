#ifndef _STRBLOBPTR_H
#define _STRBLOBPTR_H
#include <memory>
#include <exception>
#include <string>
#include "StrBlob.h"

using namespace std;


class StrBlobPtr {
    friend bool ptrEqual(StrBlobPtr &a, StrBlobPtr &b);
    friend StrBlobPtr operator+(const StrBlobPtr&, size_t n);
    friend StrBlobPtr operator-(const StrBlobPtr&, size_t n);
    public:
        StrBlobPtr() : curr(0) {};
        StrBlobPtr(StrBlob &src, uint32_t pos = 0) : wpst(src.data), curr(pos) {};
        string& deref() const {
            auto p = check(curr, "deref space not exist");
            return (*p)[curr];
        };
        StrBlobPtr& incr() {
            check(curr, "incream space not exist");
            ++curr;
            return *this;
        };
        StrBlobPtr& operator++();
        StrBlobPtr operator++(int);
        StrBlobPtr& operator--();
        StrBlobPtr operator--(int);
        string& operator*() const;
        string* operator->() const;

    private:
        weak_ptr<vector<string>> wpst;
        uint32_t curr;
        shared_ptr<vector<string>> check(int pos, const string& msg) const {
            if (auto p = wpst.lock()) {
                if (pos >= p->size())
                    throw out_of_range(msg);
                else
                    return p;
            } else {
                throw out_of_range("origin space already released");
            }
        };
};

bool ptrEqual(StrBlobPtr &a, StrBlobPtr &b)
{
    return a.curr == b.curr;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "incream space not exist");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "incream space not exist");
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr operator+(const StrBlobPtr &org, size_t n)
{
    StrBlobPtr tmp = org;
    tmp.check(tmp.curr + n - 1, "incream space not exist");
    tmp.curr += n;
    return tmp;
}

StrBlobPtr operator-(const StrBlobPtr &org, size_t n)
{
    StrBlobPtr tmp = org;
    tmp.curr -= n;
    tmp.check(tmp.curr, "incream space not exist");
    return tmp;
}
string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "deref space not exist");
    return (*p)[curr];
}

string* StrBlobPtr::operator->() const
{
    return & this->operator*();
}
#endif
