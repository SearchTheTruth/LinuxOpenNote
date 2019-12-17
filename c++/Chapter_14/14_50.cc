#include <iostream>

class LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

int main()
{
    LongDouble tmp;
    double db = tmp;  //二义性
    float ft = tmp;

    return 0;
}
