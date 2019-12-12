#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class equalStr {
    public:
        bool operator()(const string& l, const string& r) {
            return l == r;
        }
};

int main()
{
    vector<string> tmp {"hello", "world"};
    equalStr worker;
    string replace("WOW!!");

    auto func = [&worker, replace](string &ele)->void {
        if (worker(ele, "hello"))
            ele = replace;
    };
    for_each(tmp.begin(), tmp.end(), func);
    for (auto &ele : tmp) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
