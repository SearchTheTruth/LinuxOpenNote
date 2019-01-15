#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int scores;
    cin >> scores;

    //version 1
    if (scores >= 90)
        cout << "high pass" << endl;
    else if (scores >= 75 && scores < 90)
        cout << "pass" << endl;
    else if (scores >= 60 && scores < 75)
        cout << "low pass" << endl;
    else
        cout << "fail" << endl;

    //version 2
    scores >= 90 ? cout << "high pass" << endl :
        (scores >= 75 && scores < 90 ? cout << "pass" << endl :
        (scores >= 60 && scores < 75 ? cout << "low pass" << endl : cout << "fail" << endl));
}
