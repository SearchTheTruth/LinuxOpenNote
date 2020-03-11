#include <iostream>
using namespace std;

template <typename T> void f(T)
{
    std::cout << "f(T)" << std::endl;
}

template <typename T> void f(const T*)
{
    std::cout << "f(const T*)" << std::endl;
}

template <typename T> void g(T)
{
    std::cout << "g(T)" << std::endl;
}

template <typename T> void g(T*)
{
    std::cout << "g(T*)" << std::endl;
}


int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    cout << "should be g(T)" << endl;
    g(42);

    cout << "should be g(T*)" << endl;
    g(p);

    cout << "should be g(T)" << endl;
    g(ci);

    cout << "should be g(T*)" << endl;
    g(p2);

    cout << "should be f(T)" << endl;
    f(42);

    cout << "should be f(T)" << endl;  //p 是int*类型, 在传参过程中底层const也是需要传递的, 同理没有底层const就不能擅自增加const,所以不能使用f(const T*)
    f(p);

    cout << "should be f(T)" << endl;
    f(ci);

    cout << "should be f(const T*)" << endl;
    f(p2);

    return 0;
}
