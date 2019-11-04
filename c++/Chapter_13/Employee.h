#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <string>
#include <iostream>

class Employee {
    public:
        Employee() = default;
        Employee(const std::string &str) : name(str), id(seed++){
//            id = seed++;
        }
        void print(void) {
            std::cout << name << ": " << id << std::endl;
        }
    private:
        static int seed;
        std::string name;
        int id;
};

int Employee::seed = 0;

#endif
