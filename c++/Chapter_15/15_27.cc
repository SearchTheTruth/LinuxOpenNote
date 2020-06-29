#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
        Base() = default;
        Base(int i, string s = "default") : mBasei(i), mBases(s) {
            cout << "Base(int i, string s = \"default\")" << endl;
        };
        void dumpBase();
    private:
        int mBasei;
        string mBases;
};

void Base::dumpBase()
{
    cout << "mBasei = " << mBasei << endl;
    cout << "mBases = " << mBases << endl;
}

class Delver_1 : public Base {
    public:
        using Base::Base;
        void dumpDelver_1();
    private:
        int mDelveri_1 = 7;
        string mDelvers_1;
};

void Delver_1::dumpDelver_1()
{
    cout << "mDelveri_1 = " << mDelveri_1 << endl;
    cout << "mDelvers_1 = " << mDelvers_1 << endl;
};

class Delver_2 : public Base {
    public:
        using Base::Base;
        Delver_2(int i, string s) : mDelveri_2(i), mDelvers_2(s) {
            cout << "Delver_2(int i, string s)" << endl;
        };
        void dumpDelver_2();
    private:
        int mDelveri_2 = 7;
        string mDelvers_2;
};

void Delver_2::dumpDelver_2()
{
    cout << "mDelveri_2 = " << mDelveri_2 << endl;
    cout << "mDelvers_2 = " << mDelvers_2 << endl;
};



int main ()
{
    Delver_1 d1v0(1, "change");
    d1v0.dumpBase();
    d1v0.dumpDelver_1();

    Delver_1 d1v1(2);
    d1v1.dumpBase();
    d1v1.dumpDelver_1();

    Delver_2 d2v0(3, "change");
    d2v0.dumpBase();
    d2v0.dumpDelver_2();

}
