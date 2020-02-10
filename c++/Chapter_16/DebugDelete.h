#ifndef __DEBUGDELETE_H
#define __DEBUGDELETE_H
#include <iostream>

class DebugDelete {
    public:
        DebugDelete(std::ostream &s = std::cerr) : os(s){};
        template <typename T> void operator()(T *p) const {
            os << "delete p" << std::endl;
            delete p;
        }
    private:
        std::ostream &os;
};

#endif
