#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> make(int num)
{
    return unique_ptr<int> (new int(num));
}

int main()
{
    unique_ptr<int> num(new int(3));
    unique_ptr<int> tmp;
    //tmp = num;
    //这个操作是错误的会导致编译报错
    tmp.reset(num.release());

    unique_ptr<int> tmp1(tmp.release());

    tmp = make(7);
    cout << *tmp << endl;

    return 0;
}
