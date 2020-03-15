#include <iostream>
#include <string>

template <typename T, typename... Args>
void foo(const T& a, const Args& ... rest)
{
    std::cout << "template = " << sizeof...(Args) << "func = " << sizeof...(rest) << std::endl;
}

int main()
{
    int i = 0;
    double d1 = 1.0, d2 = 2.0;
    std::string s = "Hello";

    foo(i, d1, d2, s, 42);
    foo(s, 42, d1);
    foo(d1, "Hi");
    foo("Hi");

    return 0;
}
