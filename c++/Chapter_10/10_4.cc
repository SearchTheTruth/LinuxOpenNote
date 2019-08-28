#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <numeric>
using std::accumulate;

#include <vector>
using std::vector;

int main()
{
    vector<double> intline {1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1};

    cout << "sum of intline is " << accumulate(intline.begin(), intline.end(), 0.0) << endl;
    return 0;
}
