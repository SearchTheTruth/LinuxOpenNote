#include <iostream>

class Debug {
    public:
        constexpr Debug(bool val) : sw(val), hard(val), other(val) {};
        constexpr Debug(bool sv, bool hv, bool ov) : sw(sv), hard(hv), other(ov) {};
        constexpr bool isBug() {return sw || hard || other;};
        void setval(int sv, int hv, int ov);
    private:
        bool sw;        //software bug
        bool hard;      //hardware bug
        bool other;     //other bug
};

void Debug::setval(int sv, int hv, int ov) {
    sw = sv;
    hard = hv;
    other = ov;
}

int main()
{
    Debug tmp(0);
    std::cout << tmp.isBug() << std::endl;
    tmp.setval(0, 1, 0);
    std::cout << tmp.isBug() << std::endl;
    return 0;
}
