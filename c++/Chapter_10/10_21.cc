#include <algorithm>

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int num = 10;
    int ret;
    /*if equal 0, return true, else false*/
    auto reduce = [&num]() mutable -> bool {
        if (!num)
            return true;
        --num;
        return false;
    };

    cout << num << endl;
    reduce();
    cout << num << endl;

    while(!(ret = reduce()))
        cout << num << endl;
    return 0;
}
