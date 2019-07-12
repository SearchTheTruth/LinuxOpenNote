#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;
using std::ifstream;

int main()
{
    string tmp;
    vector<string> line;
    ifstream in("text_8.1.txt");

    if (in) {
        while (getline(in, tmp)) {
            line.push_back(tmp);
        }
        for (auto &ret : line) {
            std::cout << ret << std::endl;
        }
    }
    return 0;
}
