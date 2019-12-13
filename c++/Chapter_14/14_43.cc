#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    int num;
    vector<int> factor{2, 3, 4, 5};
    cin >> num;
    auto work = [&](const int &n) ->bool {
        modulus<int> mod;
        return 0 == mod(num, n);
    };
    auto ret = any_of(factor.begin(), factor.end(), work);
    cout << (ret ? "YES" : "NO") << endl;
    return 0;
}
