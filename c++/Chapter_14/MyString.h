#ifndef __MYSTRING_H
#define __MYSTRING_H

#include <memory>
#include <cstring>
#include <iostream>

using namespace std;

class Mystring{
    friend ostream& operator<<(ostream&, const Mystring&);
    public:
        Mystring() : element(nullptr), cap(nullptr) {};
        Mystring(const char* str) {
            cout << "Mystring(const char* str)  " << str << endl;
            element = alloc.allocate(strlen(str) + 1);
            memcpy(element, str, strlen(str));
            *(element + strlen(str)) = '\0';
            cap = element + strlen(str) + 2;
        }
        Mystring(const Mystring& org) {
            cout << "Mystring(const Mystring& org)  " << org.get_str() << endl;
            element = alloc.allocate(org.size());
            memcpy(element, org.element, org.size());
            cap = element + org.size();
        }
        Mystring& operator=(const Mystring& org) {
            cout << "Mystring& operator=(const Mystring& org)  " << org.get_str() << endl;
            char *newData = alloc.allocate(org.size());
            memcpy(newData, org.element, org.size());
            free();
            element = newData;
            cap = element + org.size();
            return *this;
        }
        ~Mystring() {
            cout << "free" << endl;
            free();
        }
        char* get_str() const {
            return element;
        };
        size_t size() const {
            return cap - element;
        }
    private:
        void free() {
            if (element) {
                auto free = cap;
                while (element != free)
                    alloc.destroy(--free);
                alloc.deallocate(element, size());
            }
        }
        static allocator<char> alloc;
        char *element;
        char *cap;
};

allocator<char> Mystring::alloc;

ostream& operator<<(ostream& os, const Mystring &org)
{
    auto pos = org.element;
    while (pos != org.cap) {
        os << *pos++;
    }
    return os;
}
#endif
