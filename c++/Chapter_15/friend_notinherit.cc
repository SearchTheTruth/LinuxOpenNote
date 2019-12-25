#include <iostream>

using namespace std;

class base {
    friend class friendOfBase;
    public:
        int pub_b = 1;
    private:
        int pri_b = 2;
};

class derived : public base {
    public:
        int pub_d = 3;
    private:
        int pri_d = 4;
};

class friendOfBase {
    public:
        int access_b(derived &d) {
            return d.pri_b;     //base的友元是由base自己决定,作为派生类的基类时也是一样.
        }

//        int access_d(derived &d) {
//            return d.pri_d;  //友元不可继承,friendOfBase不是derived的友元,不能访问它的私有成员.
//        }
};


int main()
{
    derived d;
    friendOfBase f;

    cout << f.access_b(d) << endl;
//    cout << f.access_d(d) << endl;
    return 0;
}
