#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string tmp("Hello, World!!");

    auto rcomma = find(tmp.crbegin(), tmp.crend(), ',');
    cout << string(tmp.crbegin(), rcomma) << endl;
    cout << string(rcomma.base(), tmp.cend()) << endl;
    /*cout << string(rcomma, tmp.crbegin()) << endl;
     *执行,会导致crash错误原因和下句相同
     *cout << string(tmp.end(), tmp.begin()) << endl;
     *推测string使用迭代器的构造函数会判断迭代器的先后顺序
     *即必须满足parameter 1 <= parameter 2
     */
    return 0;
}
