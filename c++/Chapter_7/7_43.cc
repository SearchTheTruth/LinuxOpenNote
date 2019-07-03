#include <iostream>

class NoDefault {
    public:
        NoDefault(int val) : num(val) {};
        int get_num() {return num;};
    private:
        int num;
};

class C {
    public:
        C() : def(1) {};
        int get_num() {return def.get_num();};
    private:
        NoDefault def;
};

int main()
{
    C tmp;
    std::cout << tmp.get_num() << std::endl;

    return 0;
}
