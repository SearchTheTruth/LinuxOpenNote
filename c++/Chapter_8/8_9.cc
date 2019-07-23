#include <iostream>
#include <string>
#include <sstream>


using std::istream;
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

istream &print(istream &is)
{
    char ch;
    while (is >> ch)    //same as:while (!is.eof())
        cout << ch;
    return is;
}

int main()
{
    string txt("Is a long story!!");
    stringstream strm(txt);
    print(strm);
    cout << "eof = "<< cin.eof() << std::endl;
    cin.clear(cin.rdstate() & (~cin.eofbit));
    cout << "eof = "<< cin.eof() << std::endl;
    return 0;
}
