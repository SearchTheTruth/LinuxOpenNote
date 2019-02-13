#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    string tmp;

    for (int i = 0; i < argc; i++) {
        tmp += argv[i];
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    cout << tmp << endl;

    return 0;
}
