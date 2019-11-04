#include "StrBlob.h"
#include "StrBlobPtr.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    StrBlob tom{"Tom"};
    StrBlob tom_clone(tom);
    StrBlob tom_clone2;
    tom_clone2 = tom;
    auto tom_bg = tom.begin();
    auto tomclone2_bg = tom_clone2.begin();
    cout << "tom = " << tom_bg.deref() << endl;
    cout << "tomclone2 = " << tomclone2_bg.deref() << endl;

    return 0;
}
