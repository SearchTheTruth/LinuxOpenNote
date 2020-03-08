#ifndef __OPERATIORDOUBE__H
#define __OPERATIORDOUBE__H

#include <string>
#include <memory>
#include <iostream>

using namespace std;

class level1 {
    public:
        level1() : str(new string("level1 str")) {};

        string& operator*() {
            cout << "lv1 operator*()" << endl;
            return *str;
        }

        string *operator->() {
            cout << "lv1 operator->()" << endl;
            return & this->operator*();
        }

        string *str;
};

class level2 {
    public:
        level2() : lv1(new level1()) {};

        level1& operator*() {
            cout << "lv2 operator*()" << endl;
            return *lv1;
        }

        level1* operator->() {
            cout << "lv2 operator->()" << endl;
            return & this->operator*();
        }

        level1 *lv1;
};

#endif
