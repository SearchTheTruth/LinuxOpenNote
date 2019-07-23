#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> strline;
    istringstream instr;
    string tmp;

    ifstream in("text_8.1.txt");
    getline(in, tmp);
    strline.push_back(tmp);
    instr.str(strline[0]);

    cout << instr.str();
    return 0;
}
