#include  "AdvanceQuery.h"
#include <fstream>
#include <iostream>

using namespace std;

#define TXT_PATH "../Chapter_12/txt_12_27.txt"

int main()
{
    ifstream infd(TXT_PATH);
    if (infd) {
        TextQuery txt(infd);

        cout << "word =====" << endl;
        Query word_1("fiery");
        auto w1_rst = word_1.eval(txt);
        w1_rst.print();

        cout << "not =====" << endl;
        (~Query("Daddy")).eval(txt).print();

        cout << "or =====" << endl;
        auto orword_1 = Query("hair") | Query("Alice");
        orword_1.eval(txt).print();

        cout << "and =====" << endl;
        auto andword_1 = Query("hair") & Query("Alice");
        andword_1.eval(txt).print();

        cout << "mixer=====" << endl;
        auto mixer_1 = Query("fiery") & Query("bird") | Query("wind");
        mixer_1.eval(txt).print();
    }
    return 0;
}
