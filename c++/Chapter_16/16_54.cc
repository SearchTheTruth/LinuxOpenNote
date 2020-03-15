#include <iostream>
#include <string>

using namespace std;

struct Noprint{
    int i;
};


template <typename T>
ostream& print(ostream &os, const T& t)
{
    return os << t;
}

template <typename T, typename ... Args>
ostream& print(ostream &os, const T& t, const Args& ... rest)
{
    //os << sizeof...(Args) << " " << sizeof...(rest) << endl;
    os << t << ", ";
    return print(os, rest ...);
}

int main()
{
    int i = 0;
    double d1 = 1.0, d2 = 2.0;
    string s = "Hi";
    Noprint np;

    print(cout, i, d1, s, np);
    return 0;
}
