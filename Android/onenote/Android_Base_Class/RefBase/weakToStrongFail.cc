class A : public RefBase
{

};

int main()
{
    A *pA = new A;
    wp<A> wpA(pA);
    {
        sp<A> spA(pA);
    }                          //pA对象的最后一个sp被释放
    sp<A> p = wpA.promote();   //这里pA对象不能再由wp生成sp
}
