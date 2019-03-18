#ifndef _PERSON_H
#define _PERSON_H
#include <string>

struct person {
    std::string name;
    std::string addr;
    std::string isName() const {return name;};
    std::string isAddr() const {return addr;};
};


#endif
