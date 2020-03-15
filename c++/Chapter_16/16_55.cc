#include <iostream>
#include <string>

using namespace std;

template <typename T, typename ... Args>
ostream& print(ostream &os, const T& t, const Args& ... rest)
{
    //os << sizeof...(Args) << " " << sizeof...(rest) << endl;
    os << t << ", ";
    return print(os, rest ...);
}

template <typename T>
ostream& print(ostream &os, const T& t)
{
    return os << t;
}

int main()
{
    int i = 0;
    double d1 = 1.0, d2 = 2.0;
    string s = "Hi";

    print(cout, i, d1, s);
    return 0;
}
