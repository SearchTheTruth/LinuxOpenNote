#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <iostream>

class BoxPtr {
    public:
        BoxPtr(StrBlobPtr &org) : blobPtr(&org) {};
        StrBlobPtr* operator->();
        StrBlobPtr& operator*();
    private:
        StrBlobPtr *blobPtr;
};

StrBlobPtr* BoxPtr::operator->()
{
    return & this->operator*();
}

StrBlobPtr& BoxPtr::operator*()
{
    if(blobPtr)
        return *blobPtr;
}

int main()
{
    StrBlob word{"hello", "world"};
    StrBlobPtr wordPtr(word);
    BoxPtr ptrBox(wordPtr);

    std::cout << ptrBox->deref() << std::endl;
    return 0;
}
