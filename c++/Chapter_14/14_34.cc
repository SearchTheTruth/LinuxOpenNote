#include <iostream>

using namespace std;

class judge {
    public:
        int operator()(int condition, int first, int second) {
            if (condition)
                return first;
            else
                return second;
        }
};

int main()
{
    judge worker;
    cout << worker(1, 77, 99) << endl;
    cout << worker(0, 77, 99) << endl;
}
