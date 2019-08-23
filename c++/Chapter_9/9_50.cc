#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    vector<string> vecint{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int sum = 0;

    for (const auto &str : vecint) {
        sum += stoi(str);
    }
    cout << sum << endl;

    vector<string> vecdou{"1.1", "2.1", "3.1", "4.1", "5.1", "6.1", "7.1", "8.1", "9.1"};
    double db = 0;

    for (const auto &str : vecdou) {
        db += stod(str);
    }
    cout << db << endl;
    return 0;
}
