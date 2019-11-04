#ifndef _STRBLOBPTR_H
#define _STRBLOBPTR_H
#include <memory>
#include <exception>
#include <string>

using namespace std;


class StrBlobPtr {
    friend bool ptrEqual(StrBlobPtr &a, StrBlobPtr &b);
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

#endif
