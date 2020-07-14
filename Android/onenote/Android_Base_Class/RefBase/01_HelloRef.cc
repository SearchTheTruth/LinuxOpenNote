#include <iostream>

class A : public RefBase
{

}

int main ()
{
    A *pA = new A;
    {
        sp<A> spA(pA);
        wp<A> wpA(spA);
    }       // 注意此处wp, sp的生命周期结束, 先析构wp，再析构sp.
}
