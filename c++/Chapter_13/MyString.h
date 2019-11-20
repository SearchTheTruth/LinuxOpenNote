#ifndef __MYSTRING_H
#define __MYSTRING_H

#include <memory>
#include <cstring>

using namespace std;

class Mystring{
    public:
        Mystring() : element(nullptr), cap(nullptr) {};
        Mystring(const char* str) {
            element = alloc.allocate(strlen(str) + 1);
            memcpy(element, str, strlen(str));
            *(element + strlen(str)) = '\0';
            cap = element + strlen(str) + 1;
        }
        char* get_str() {return element;};
    private:
        static allocator<char> alloc;
        char *element;
        char *cap;
};

allocator<char> Mystring::alloc;

#endif
