#ifndef __STRVEC_H
#define __STRVEC_H

#include <memory>
#include <string>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iostream>


using namespace std;

class StrVec {
    friend ostream& operator<<(ostream&, const StrVec&);
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    public:
        StrVec() : element(nullptr), first_free(nullptr), cap(nullptr), rzerv(0) {};
        StrVec(initializer_list<string> list) {
            auto ret = alloc_n_copy(list.begin(), list.end());
            element = ret.first;
            first_free = cap = ret.second;
            rzerv = list.size();
        }
        StrVec(const StrVec& org) {
            auto ret = alloc_n_copy(org.begin(), org.end());
            element = ret.first;
            first_free = cap = ret.second;
            rzerv = org.rzerv;
        }
        ~StrVec() {
            free();
        }
        StrVec& operator=(const StrVec& org) {
            auto ret = alloc_n_copy(org.begin(), org.end());
            free();
            element = ret.first;
            first_free = cap = ret.second;
            rzerv = org.rzerv;
            return *this;
        }
        size_t size() {
            return first_free - element;
        }
        size_t capacity() {
            return cap - element;
        }
        size_t reserve(size_t expect) {
            rzerv = expect;
        }
        void resize(size_t n) {
            if (n < size()) {
                for (size_t i = n; i < size(); ++i)
                    alloc.destroy(element + i);
                first_free = element + n;
            } else {
                while (n < capacity())
                    reallocate();
                for (size_t i = size(); i < n; ++i)
                    alloc.construct(first_free++, string());
            }
        }
        void push_back(const string& str) {
            chk_n_alloc();
            alloc.construct(first_free++, str);
        }
        string* begin() const{
            return element;
        }
        string* end() const{
            return first_free;
        }

    private:
        pair<string*, string*> alloc_n_copy(auto* b, auto* e) {
            auto newData = alloc.allocate(e - b);
            return {newData, uninitialized_copy(b, e, newData)};
        }
        void chk_n_alloc() {
            if (first_free == cap)
                reallocate();
        }
        void free() {
            if (element) {
                for(; element != first_free; --first_free)
                    alloc.destroy(first_free);
                alloc.deallocate(element, capacity());
            }
        }
        void free_v2() {
            if (element) {
                for_each(element, first_free, [](string& ptr){alloc.destroy(&ptr);});
                alloc.deallocate(element, capacity());
            }
        }
        void reallocate() {
            size_t newSize = size() ? size() * 2 : 1;
            if (rzerv > size())
                newSize = rzerv;
            auto newData = alloc.allocate(newSize);
            auto dest = newData;
            auto elem = element;
            for(size_t i = 0; i < size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            element = newData;
            first_free = dest;
            cap = element + newSize;
        }
        static allocator<string> alloc;
        string* element;
        string* first_free;
        string* cap;
        size_t rzerv;
};

allocator<string> StrVec::alloc;

bool operator==(const StrVec& l, const StrVec& r)
{
    if (l.first_free - l.element != r.first_free - r.element)
        return false;

    auto lpos = l.element;
    auto rpos = r.element;
    while (lpos != l.first_free) {
        if (*lpos++ != *rpos++)
            return false;
    }
    return true;
}

bool operator!=(const StrVec& l, const StrVec& r)
{
    return !(l == r);
}

bool operator<(const StrVec& l, const StrVec& r)
{
    if (l == r)
        return false;
    else {
        if (l.first_free - l.element == r.first_free - r.element) {
            auto lpos = l.element;
            auto rpos = r.element;
            while (lpos != l.first_free) {
                if (*lpos != *rpos)
                    return *lpos < *rpos;
                ++lpos;
                ++rpos;
            }
        } else if (l.first_free - l.element < r.first_free - r.element) {
            return true;
        } else {
            return false;
        }
    }
}

bool operator>(const StrVec& l, const StrVec& r)
{
    return (l != r) && !(l < r);
}


ostream& operator<<(ostream& os, const StrVec& org)
{
    auto pos = org.element;
    while (pos != org.first_free) {
        os << *pos++ << " ";
    }
    return os;
}
#endif
