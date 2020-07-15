class A : public RefBase {
    public:
        A() {
            extendObjectLifetime(OBJECT_LIFETIME_WEAK);   //在构造函数中调用
        }
}

int main ()
{
    A *pA = new A;
    wp<A> wpA(pA);
    {
        sp<A> sp(pA);
    }                       //这里释放sp
    ...
}
