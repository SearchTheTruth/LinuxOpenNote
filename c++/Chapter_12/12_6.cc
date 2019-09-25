#include <vector>
#include <memory>
#include <iostream>
#include <exception>

using namespace std;

void input(vector<int> *p)
{
    int num;
    while (cin >> num) {
        p->push_back(num);
    }
}

void output(vector<int> *p)
{
    cout << "output====" << endl;
    for (const auto ele : *p) {
        cout << ele << " ";
    }
    cout << endl;
}



int main()
{
    vector<int> *p = new vector<int>;

    input(p);
    output(p);
    delete p;
    return 0;
}
