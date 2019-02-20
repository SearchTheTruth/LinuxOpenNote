#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << make_plural(1, "success", "es") << " " << make_plural(1, "success") <<endl;
    cout << make_plural(2, "failure", "es") << " " << make_plural(2, "failure") <<endl;

    return 0;
}

