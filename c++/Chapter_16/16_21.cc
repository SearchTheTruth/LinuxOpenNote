#include "DebugDelete.h"
#include <vector>
#include <memory>

int main()
{
    int *ip = new int(1);
    double *dp = new double(2.0);

    DebugDelete d;
    d(ip);

    DebugDelete()(dp);

    return 0;
}
