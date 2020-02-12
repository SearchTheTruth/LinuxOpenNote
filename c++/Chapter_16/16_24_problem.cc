#include <vector>

using namespace std;

int main()
{
    vector<int> org{0, 1, 2};

    vector<int> dst(org.begin(), org.end());

    //dst.insert(org.begin(), org.end());
    return 0;
}
