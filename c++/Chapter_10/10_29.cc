#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<string> vecStr;
    fstream fs("10_29_file.txt", ifstream::in);
    if (fs){
        istream_iterator<string> os(fs), eof;
        copy(os, eof, back_inserter(vecStr));
    } else {
        cout << "open failed" << endl;
        return 0;
    }
    copy(vecStr.begin(), vecStr.end(), ostream_iterator<string> (cout, " "));
    return 0;
}
