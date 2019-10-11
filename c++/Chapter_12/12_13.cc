#include <memory>
#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> org(new int(7));
    cout << *org << endl;
    delete org.get(); //org指向的对象被释放后再去操作智能指针可能导致的后果时未定义的
    cout << "after delete" << endl;
    cout << *org << endl;
    return 0;
}
