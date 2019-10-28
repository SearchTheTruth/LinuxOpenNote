#include <iostream>
#include <string>
#include <memory>

class HasPts {
    friend void print(const HasPts &input);
    public:
    HasPts& operator=(const HasPts& org) {
        if (!ps)
            delete ps;
        ps = new std::string(*(org.ps));
        i = org.i;
        return *this;
    }
    HasPts(const std::string &s) : ps(new std::string(s)), i(0) {};
    HasPts(const HasPts &org) : ps(new std::string(*(org.ps))), i(org.i) {};
    private:
        std::string *ps;
        int i;
};

void print(const HasPts &input)
{
    std::cout << "ad: " << input.ps << " cnt: " << *(input.ps) << std::endl;
}

int main()
{
    HasPts org("org");
    print(org);
    HasPts dst(org);
    print(dst);
    HasPts equal("equal");
    print(equal);
    equal = org;
    print(equal);
    return 0;
}
