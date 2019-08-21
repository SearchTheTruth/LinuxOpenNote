#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    vector<char> chvec {'H', 'e', 'l', 'l', 'o'};

    string str(chvec.begin(), chvec.end());
    cout << str << endl;
    return 0;
}
