#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    char ch;
    string str;
    str.reserve(100);
    cin >> ch;
    str.push_back(ch);
    cout << str << endl;
    cout << "capacity = " << str.capacity() << endl;
    return 0;
}
