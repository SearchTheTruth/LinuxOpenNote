#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main()
{
    string line;

    cout << "getline" << endl;
    while (getline(cin, line)){
        cout << line;
        if (line == "00")
            break;
    }
    cout << "one word" << endl;
    while (cin >> line){
        cout << line;
    }
    return 0;
}
