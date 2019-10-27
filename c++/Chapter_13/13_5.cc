#include <iostream>
#include <string>
#include <memory>

class HasPts {
    friend void print(const HasPts &input);
    public:
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
    return 0;
}
