#include <iostream>

class base {
    protected:
        int prct_mem = 7;
};

class derived : public base {
    friend int access_d(derived &d);
    friend int access_b(base &b);
};


int access_d(derived &d)
{
    return d.prct_mem;
}

int access_b(base &b)
{
//    只能通过b的派生类d访问,d的友元对于b并没有访问特权
//    b.prct_mem;
    return 0;
}

int main()
{
    derived tmp;
    std::cout << access_d(tmp) << std::endl;
    return 0;
}
