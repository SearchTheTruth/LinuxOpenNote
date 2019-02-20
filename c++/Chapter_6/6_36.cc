#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string one[10] = {"1th", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed"};
string two[10] = {"2th", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed"};
string three[10] = {"3th", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed"};
string four[10] = {"4th", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed", "ed"};

//返回一个数组的引用
string (&origin_return(int index))[10]
{
    switch (index) {
        case 1:
        return one;
        case 2:
        return two;
        case 3:
        return three;
        case 4:
        return four;
    }
    return four;
}

//typedef 返回一个数组的引用
typedef string strT[10];

strT &typedef_return(int index)
{
    switch (index) {
        case 1:
        return one;
        case 2:
        return two;
        case 3:
        return three;
        case 4:
        return four;
    }

    return four;
}


//尾置类型返回数组引用
auto end_return(int index) -> string (&)[10]
{
    switch (index) {
        case 1:
        return one;
        case 2:
        return two;
        case 3:
        return three;
        case 4:
        return four;
    }

    return four;
}

//decltype返回数组引用
decltype(four) &decltype_return(int index)
{
    switch (index) {
        case 1:
        return one;
        case 2:
        return two;
        case 3:
        return three;
        case 4:
        return four;
    }

    return four;
}

int main()
{
    string (&origin)[10] = origin_return(1);
    for(int i = 0; i < 10; i++) {
        cout << origin[i] << " ";
    }
    cout << endl;

    string (&type)[10] = typedef_return(2);
    for(int i = 0; i < 10; i++) {
        cout << type[i] << " ";
    }
    cout << endl;

    string (&end)[10] = end_return(3);
    for(int i = 0; i < 10; i++) {
        cout << end[i] << " ";
    }
    cout << endl;

    string (&decl)[10] = decltype_return(4);
    for(int i = 0; i < 10; i++) {
        cout << decl[i] << " ";
    }
    cout << endl;

    return 0;
}
