#include <iostream>

using namespace std;

class base {
    public:
        int body() {
            cout << "base::body()" << endl;
            return num;
        }
        int body(int n) {
            cout << "base::body(int n)" << endl;
            num = n;
            return num;
        }
        virtual int body(int a, int b) {
            cout << "virtual base::body(int a, int b)" << endl;
            return a - b;
        }
    private:
        int num = 3;
};

class derivde : public base {
    public:
        using base::body;
        int body(int n) {
            cout << "derivde::body(int a, int b)" << endl;
            return 0;
        }
};

int main()
{
    base b;
    cout << b.body() << endl;
    cout << b.body(2) << endl;
    cout << b.body(3, 2) << endl;

    derivde d;
    cout << d.body() << endl;
    cout << d.body(2) << endl;
    cout << d.body(3, 2) << endl;
}
