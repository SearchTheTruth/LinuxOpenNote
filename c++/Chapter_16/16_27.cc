#include <iostream>

using namespace std;

template <typename T> class Stack
{
    public:
        Stack() {
            cout << "init" << endl;
        };
};

void f1(Stack<char>)
{
    cout << "f1(Stack<char>)" << endl;
}

class normal {
    Stack<double> &rsd;
    Stack<int> si;
};

int main()
{
    Stack<int> ic;
    Stack<char> *sc;
    f1(*sc);
    int size = sizeof(Stack<int>);
}
