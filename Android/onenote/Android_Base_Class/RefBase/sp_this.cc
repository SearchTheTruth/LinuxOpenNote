#include <iostream>
#include <memory>

template <typename T>
class sp {
    public:
        sp(T *other) {
            std::cout << "sp construct this = " << this << std::endl;
            other->incStrong(this);
        };
};

class RefBase {
    public:
        void incStrong(const void * id) {
            std::cout << "incStrong this = " << this << " id = " << id << std::endl;
        };
};

int main()
{
    RefBase *pA = new RefBase;
    sp<RefBase> spA(pA);
    std::cout << "pA = " << static_cast<void*>(pA) << " spA = " << static_cast<void*>(&spA) << std::endl;
}
