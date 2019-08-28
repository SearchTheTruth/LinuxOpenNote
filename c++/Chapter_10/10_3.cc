#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <numeric>
using std::accumulate;

#include <vector>
using std::vector;

int main()
{
    vector<int> intline {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "sum of intline is " << accumulate(intline.begin(), intline.end(), 0) << endl;
    return 0;
}
