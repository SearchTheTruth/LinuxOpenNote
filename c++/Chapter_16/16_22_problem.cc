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

    share_ptr<int> c(q, DebugDelete());
    return 0;
}
