#include "MyString.h"
#include "StrVec.h"
#include <iostream>

using namespace std;

int main()
{
    Mystring tmp ("helloworld");
    cout << tmp << endl;
    cout << tmp[0] << " " << tmp[1] << endl;
    tmp[0] = 'j';
    tmp[1] = 'h';
    cout << tmp << endl;

    StrVec tmp1{"hello", "world"};
    cout << tmp1[0] << " " << tmp1[1] << endl;
    tmp1[0] = "destory";
    tmp1[1] = "everything";
    cout << tmp1[0] << " " << tmp1[1] << endl;
    return 0;
}
