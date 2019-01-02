#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

void dump_int(const vector<int> &int_vec)
{
    vector<int>::size_type length = int_vec.size();

    cout << "len = " << length << endl;

    if (length == 0)
        cout << "vector is empty" << endl;
    else {
        for (auto i : int_vec)
            cout << i << " ";
        cout << endl;
    }
    cout << "===========================" << endl;
}

void dump_str(const vector<string> &str_vec)
{
    vector<string>::size_type length = str_vec.size();

    cout << "len = " << length << endl;

    if (length == 0)
        cout << "vector is empty" << endl;
    else {
        for (auto i : str_vec)
            cout << i << " ";
        cout << endl;
    }
    cout << "===========================" << endl;
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

    dump_int(v1);
    dump_int(v2);
    dump_int(v3);
    dump_int(v4);
    dump_int(v5);
    dump_str(v6);
    dump_str(v7);

    return 0;
}
