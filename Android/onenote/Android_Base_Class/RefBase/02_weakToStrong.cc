class A : public RefBase
{

};

int main ()
{
    A *pA = new A;
    wp<A> wpA(pA);
    sp<A> spA = wpA.promote();  //通过promote()得到一个sp
}
