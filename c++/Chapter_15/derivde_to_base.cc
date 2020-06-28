#include <iostream>

using namespace std;

class base {
    public:
        int a = 1;
    protected:
        int b = 2;
};

class pub_derived : public base {
    public:
        int n = 7;
        void derived_body(void) {
            base *ptr = new pub_derived; //任何情况都可由派生类转换为直接基类
        }
};

class private_derived : private base {
    public:
        int n = 7;
        void derived_body(void) {
            base *ptr = new pub_derived; //任何情况都可由派生类转换为直接基类
        }
};

class protected_derived : protected base {
    public:
        int n = 7;
        void derived_body(void) {
            base *ptr = new pub_derived; //任何情况都可由派生类转换为直接基类
        }
};

class pub_grandfather : public pub_derived {
    public:
        int f = 9;
        void gf_body(void) {
            base *ptr = new pub_grandfather;
        }
};

class private_grandfather : public private_derived {
    public:
        int f = 9;
        void gf_body(void) {
            //base *ptr = new private_grandfather;  //d是以私有方式继承基类,所以d的派生类不能转换为d的直接基类.
        }
};

class protected_grandfather : public protected_derived {
    public:
        int f = 9;
        void gf_body(void) {
            //此处可以访问到基类的公共成员，所以可以进行protected_grandfather到base的转换.
            protected_grandfather::protected_derived::base::a;
            base *ptr = new protected_grandfather;
        }
};

int main()
{
    pub_derived pub_d;
    private_derived pri_d;
    protected_derived ptc_d;

    base &p1 = pub_d;
//    base &p2 = pri_d;
//    base &p3 = ptc_d;
//    私用或保护继承，用户代码不能转换



}
