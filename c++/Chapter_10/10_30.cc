#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> is(cin), eof;
    vector<int> tmp;
    copy(is, eof, back_inserter(tmp));
    sort(tmp.begin(), tmp.end());

    copy(tmp.begin(), tmp.end(), ostream_iterator<int> (cout, " "));
    cout << endl;
    return 0;
}
