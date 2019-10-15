#include "StrBlob.h"
#include <fstream>


int main()
{
    ifstream infile("txt_12_20.txt");
    string tmp;
    StrBlob in;

    if (!infile) {
        cout << "can not open file" << endl;
        return 0;
    }

    while (infile >> tmp) {
        in.push_back(tmp);
    }

    StrBlobPtr beg = in.begin(), end = in.end();
    while(!ptrEqual(beg, end)) {
        cout << beg.deref() << endl;
        beg.incr();
    }
    return 0;
}
