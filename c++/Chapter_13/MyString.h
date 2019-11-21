#ifndef __MYSTRING_H
#define __MYSTRING_H

#include <memory>
#include <cstring>
#include <iostream>

using namespace std;

class Mystring{
    public:
        Mystring() : element(nullptr), cap(nullptr) {};
        Mystring(const char* str) {
            cout << "Mystring(const char* str)  " << str << endl;
            element = alloc.allocate(strlen(str) + 1);
            memcpy(element, str, strlen(str));
            *(element + strlen(str)) = '\0';
            cap = element + strlen(str) + 1;
        }
        Mystring(const Mystring& org) {
            cout << "Mystring(const Mystring& org)  " << org.get_str() << endl;
            element = alloc.allocate(org.size());
            memcpy(element, org.element, org.size());
            cap = element + org.size();
        }
        Mystring& operator=(const Mystring& org) {
            cout << "Mystring& operator=(const Mystring& org)  " << org.get_str() << endl;
            element = alloc.allocate(org.size());
            memcpy(element, org.element, org.size());
            cap = element + org.size();
            return *this;
        }
        ~Mystring() {
            cout << "free" << endl;
            if (element) {
                auto free = cap;
                while (element != free)
                    alloc.destroy(--free);
                alloc.deallocate(element, size());
            }
        }
        char* get_str() const {
            return element;
        };
        size_t size() const {
            return cap - element;
        }
    private:
        static allocator<char> alloc;
        char *element;
        char *cap;
};

allocator<char> Mystring::alloc;

#endif
