#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    string num ("0123456789");
    string exam ("ab2c3d7R4E6");

    cout << "num:" << endl;
    for (size_t idx = 0; (idx = exam.find_first_of(num, idx)) != string::npos; ++idx)
        cout << "exam[" << idx << "] :" << exam[idx] << " ";
    cout << endl;

    cout << "character:" << endl;
    for (size_t idx = 0; (idx = exam.find_first_not_of(num, idx)) != string::npos; ++idx)
        cout << "exam[" << idx << "] :" << exam[idx] << " ";
    cout << endl;
}
