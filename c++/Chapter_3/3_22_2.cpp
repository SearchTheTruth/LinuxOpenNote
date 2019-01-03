#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


int main ()
{
    vector<string> vec_text;
    string tmp;

    while (cin >> tmp)
        vec_text.push_back(tmp);

    cout << "ORIGIN: ";
    for (auto str : vec_text)
        cout << str << " ";
    cout << endl;

    for (auto it = vec_text.begin();
            it != vec_text.end() && !it->empty(); ++it) {
        for (auto &ch : (*it))
            ch = toupper(ch);
    }

    cout << "CHANGED: ";
    for (auto str : vec_text)
        cout << str << " ";
    cout << endl;

    return 0;
}
