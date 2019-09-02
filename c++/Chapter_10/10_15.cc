#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int sz = 10;
    auto in_lambda = [sz](int a) -> int {return sz + a;};
    cout << in_lambda(90) << endl;
}
