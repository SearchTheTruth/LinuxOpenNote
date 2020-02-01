#ifndef __BLOB_H
#define __BLOB_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <exception>
#include <initializer_list>

using namespace std;

template <typename> class BlobPtr;

template <typename T> class Blob
{
    friend class BlobPtr<T>;
    typedef typename vector<T>::size_type size_type;
    public:
        Blob() : data(make_shared<vector<T>>()) {};
        Blob(const initializer_list<T> &il) : data(make_shared<vector<T>>(il)) {};
        void push_back(const T &);
        void pop_back();
        T& back() const;
        BlobPtr<T> begin();
        BlobPtr<T> end();
    private:
        shared_ptr<vector<T>> data;
        void check(size_type pos, const string &msg) const;
};

template <typename T> void Blob<T>::push_back(const T &elem)
{
    data->push_back(elem);
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "pop on empty container");
    data->pop_back();
}

template <typename T> T& Blob<T>::back() const
{
    check(0, "back on empty container");
    return data->back();
}

template <typename T> void Blob<T>::check(size_type pos, const string &msg) const
{
    if (pos >= data->size())
        throw out_of_range(msg);
}

template <typename T> BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T> BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

#endif
