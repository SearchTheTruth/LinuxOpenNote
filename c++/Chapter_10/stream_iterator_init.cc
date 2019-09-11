#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> in(cin);
    istream_iterator<int> eof;

    vector<int> exp(in, eof);


    cout << "print vector" << endl;
    for (const auto &num : exp)
        cout << num << " ";
    cout << endl;
    return 0;
}

