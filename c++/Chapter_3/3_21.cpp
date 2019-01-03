#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


void dumpint(const vector<int> src)
{
    auto head = src.cbegin();
    auto tail = src.cend();
    if (head == tail)
        cout << "size: 0" << endl;
    else {
        cout << "size: " << src.size() << endl;
        for(; head != tail; head++)
            cout << *head << " ";
        cout << endl;
    }
    cout << "====================" << endl;
}

void dumpstr(const vector<string> src)
{
    auto head = src.cbegin();
    auto tail = src.cend();
    if (head == tail)
        cout << "size: 0" << endl;
    else {
        cout << "size: " << src.size() << endl;
        for(; head != tail; head++)
            cout << *head << " ";
        cout << endl;
    }
    cout << "====================" << endl;
}

int main()
{
    vector<int> v1;                 // size:0,  no values.
    vector<int> v2(10);             // size:10, value:0
    vector<int> v3(10, 42);         // size:10, value:42
    vector<int> v4{10};             // size:1,  value:10
    vector<int> v5{10, 42};         // size:2,  value:10, 42
    vector<string> v6{10};          // size:10, value:""
    vector<string> v7{10, "hi"};    // size:10, value:"hi"


    dumpint(v1);
    dumpint(v2);
    dumpint(v3);
    dumpint(v4);
    dumpint(v5);
    dumpstr(v6);
    dumpstr(v7);

    return 0;
}

