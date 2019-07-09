#include <iostream>

using std::istream;
using std::cin;
using std::cout;

istream &print(istream &is)
{
    char ch;
    while (is >> ch)    //same as:while (!is.eof())
        cout << ch;
    return is;
}

int main()
{
    print(cin);
    cout << "eof = "<< cin.eof() << std::endl;
    cin.clear(cin.rdstate() & (~cin.eofbit));
    cout << "eof = "<< cin.eof() << std::endl;
    return 0;
}
