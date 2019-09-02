#include <iostream>
using std::cout; using std::cin; using std::endl;

auto out_lambda = [](int a, int b) -> int {return a + b;};

int main()
{
    auto in_lambda = [](int a, int b) -> int {return a + b;};
    cout << out_lambda(12, 1) << endl;
    cout << in_lambda(11, 111) << endl;
    return 0;
}
