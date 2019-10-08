#include <vector>
#include <memory>
#include <iostream>
#include <exception>

using namespace std;

void input(shared_ptr<vector<int>> p)
{
    int num;
    while (cin >> num) {
        p->push_back(num);
    }
}

void output(shared_ptr<vector<int>> p)
{
    cout << "output====" << endl;
    for (const auto ele : *p) {
        cout << ele << " ";
    }
    cout << endl;
}



int main()
{
    shared_ptr<vector<int>> p = make_shared<vector<int>>();
    input(p);
    output(p);
    return 0;
}
