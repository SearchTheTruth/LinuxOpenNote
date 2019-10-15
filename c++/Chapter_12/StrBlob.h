#ifndef _STRBLOB_H
#define _STRBLOB_H
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <initializer_list>

using namespace std;

class StrBlobPtr;

class StrBlob {
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
    public:
        StrBlob() : data(make_shared<vector<string>>()) {};
        StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};
        bool empty() const {
            return data->empty();
        };
        string &front() const {
            check(0, "front on empty vec");
            return data->front();
        };
        string &back() const {
            check(0, "back on empty vec");
            return data->back();
        };
        size_type size() const {
            return data->size();
        };
        void push_back(const string &str) {
            data->push_back(str);
        };
        void pop_back() {
            check(0, "pop on empty vec");
            return data->pop_back();
        };
        int use_count() const {
            return data.use_count();
        };
        StrBlobPtr begin();
        StrBlobPtr end();
       private:
        shared_ptr<vector<string>> data;
        void check(size_type i, const string &msg) const {
            if (i >= data->size())
                throw out_of_range(msg);
        };
};

#include "StrBlobPtr.h"

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

#endif
