#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <iostream>

using namespace std;

int main()
{
    StrBlob tmp {"1th", "2th", "3th", "4th", "5th"};
    StrBlobPtr ptr(tmp);
    cout << ptr.deref() << endl;
    cout << (++ptr).deref() << endl;
    cout << ptr.deref() << endl;
    cout << (ptr++).deref() << endl;
    cout << ptr.deref() << endl;
    cout << (ptr + 2).deref() << endl;
    return 0;
}
