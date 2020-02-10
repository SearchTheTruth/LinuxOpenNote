#include  "TextQuery.h"
#include <fstream>
#include <iostream>

using namespace std;

#define TXT_PATH "../Chapter_12/txt_12_27.txt"

int main()
{
    ifstream infd(TXT_PATH);
    if (infd) {
        TextQuery txt(infd);

        auto ret = txt.query("Dad");
        ret.print();
    }
    return 0;
}
