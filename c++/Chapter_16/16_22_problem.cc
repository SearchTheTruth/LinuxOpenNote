#include <memory>
#include "DebugDelete.h"
#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> p(new int(), DebugDelete());
    shared_ptr<int> q;
    q = make_shared<int>(0);
    q = p;

    int *ip, *ip2;
    shared_ptr<int> c(ip, DebugDelete());   //right
    //shared_ptr<int> c(p, DebugDelete());   //error 只接受普通指针

    shared_ptr<int> d;
    d.reset(ip2, DebugDelete());            //right
    //d.reset(p, DebugDelete());            //error 只接受普通指针
    return 0;
}
