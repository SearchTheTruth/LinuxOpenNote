#include <iostream>
#include <cstdarg>

using std::cout;
using std::endl;

int average (int count, ...)
{
    va_list ap, cp;
    int sum = 0;

    va_start(ap, count);
    va_copy(cp, ap);

    for (int i = 0 ;i < count; i++)
        cout << va_arg(cp, int) << " ";
    cout << endl;

    for (int i = 0 ;i < count; i++)
        sum += va_arg(ap, int);

    va_end(ap);
    va_end(cp);

    return sum/count;
}

int main()
{
    cout << average(3, 1, 2, 3) << endl;
    cout << average(5, 0, 3, 2, 5, 5) << endl;
    return 0;
}
