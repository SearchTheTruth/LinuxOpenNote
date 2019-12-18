#include <iostream>
#include <string>

using namespace std;

class base {
    public:
        base(const string &name) : basename(name) {};
        virtual void print(ostream &os) const {
            os << __func__ << "++" << endl;
            os << "base:: " << basename << endl;
            os << __func__ << "--" << endl;
        };
        string name() { return basename;};
    private:
        string basename;
};

class derived : public base {
    public:
        derived(const string &name, const int &num) : base(name), i(num) {};
        void print(ostream &os) const override {
            os << __func__ << "++" << endl;
            base::print(os);
            os << "index:: " << i << endl;
            os << __func__ << "--" << endl;
        };
    private:
        int i;
};


int main()
{
    base b("base");
    derived d("derived", 1);

    b.print(cout);
    d.print(cout);


    return 0;
}
