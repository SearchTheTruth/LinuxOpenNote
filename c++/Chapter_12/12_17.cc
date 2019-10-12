#include <memory>
#include <iostream>

using namespace std;

int main()
{
    int num = 3, *p = &num;
    unique_ptr<int> ptr(p);
    unique_ptr<int> ptr1(&num);

    cout << "p=" << *ptr << " num=" << *ptr1 << endl;
    return 0;
}
