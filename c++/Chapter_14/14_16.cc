#include "StrVec.h"
#include <iostream>

using namespace std;

int main()
{
    StrVec word_1 {"hello"};
    StrVec word_2 {"hello", "world"};
    StrVec word_3 {"book"};

    cout << word_1 << " < " << word_2 << " " << (word_1 < word_2) << endl;
    cout << word_1 << " < " << word_3 << " " << (word_1 < word_3) << endl;
    cout << word_2 << " == " << word_2 << " " << (word_2 == word_2) << endl;
    return 0;
}
