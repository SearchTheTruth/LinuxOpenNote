#include "StrBlob.h"

int main()
{
    StrBlob str1;
    {
        StrBlob str2 {"Hello", "World"};
        str1 = str2;
    }
    cout << str1.front() << " " << str1.back() << endl;
    cout << "str1.use_count = " << str1.use_count() << endl;
    return 0;
}
