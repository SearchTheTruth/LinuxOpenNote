#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> tmp;
    if (argc < 4)
        return 0;
    ifstream fs(argv[1]);
    istream_iterator<int> is(fs), eof;
//    istream_iterator<int> is(ifstream (argv[1])), eof;
    copy(is, eof, back_inserter(tmp));
    auto oddEnd = partition(tmp.begin(), tmp.end(), [](const int num) -> bool {return num & 0x1;});
    ofstream outOdd (argv[2]);
    ofstream outEven (argv[3]);
    if (outOdd)
        copy(tmp.begin(), oddEnd, ostream_iterator<int> (outOdd, " "));
    if (outEven)
        copy (oddEnd, tmp.end(), ostream_iterator<int> (outEven, "\n"));
}
