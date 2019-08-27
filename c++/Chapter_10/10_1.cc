#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <algorithm>
using std::count;

#include <vector>
using std::vector;

int main()
{
    int num;
    vector<int> intline;
    while (cin >> num) {
        intline.push_back(num);
    }
    cout << "17 is appear " << count(intline.begin(), intline.end(), 17) << "times" << endl;
    return 0;
}
