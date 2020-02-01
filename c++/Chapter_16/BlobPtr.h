#ifndef __BLOBPTR_H
#define __BLOBPTR_H

#include <memory>
#include <vector>
#include <string>
#include <exception>
#include "Blob.h"

using namespace std;

template <typename T> class BlobPtr
{
    typedef typename vector<T>::size_type size_type;
    public:
        BlobPtr(const Blob<T> &src, size_type pos = 0) : wptr(src.data), curr(pos) {};
        T& operator*();
        BlobPtr& operator++();      //forword
        BlobPtr operator++(int);    //afterword
    private:
        size_type curr;
        weak_ptr<vector<T>> wptr;
        shared_ptr<vector<T>> check(size_type pos, const string &msg);
};

template <typename T> T& BlobPtr<T>::operator*()
{
    auto p = check(curr, "dref on invaild point");
    return (*p)[curr];
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr + 1, "incream pointer error");
    curr++;
    return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
    auto ret = *this;
    ++*this;
    return ret;
}

template <typename T> shared_ptr<vector<T>> BlobPtr<T>::check(size_type pos, const string &msg)
{
    if (auto p = wptr.lock()) {
        if (pos >= p->size())
            throw out_of_range(msg);
        else
            return p;
    } else {
        throw out_of_range("weak_ptr pointing space already be released");
    }
}
#endif

