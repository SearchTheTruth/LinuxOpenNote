#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <iostream>

using namespace std;

int main()
{
    StrBlob tmp{"hello", "world"};
    StrBlobPtr p(tmp);
    cout << *p << endl;
    cout << p->size() << endl;
    return 0;
}
