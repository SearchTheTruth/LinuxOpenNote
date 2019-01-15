#include <iostream>
#include <vector>


using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec (10, 0);
    auto cnt = ivec.size();

    for (vector<int>::size_type ix = 0; ix < ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;

    for(auto &num : ivec)
        cout << num << " ";
    cout << endl;

    return 0;
}

