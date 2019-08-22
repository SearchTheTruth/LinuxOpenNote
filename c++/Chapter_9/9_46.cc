#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void combin(string &name, const string &bef, const string &aft)
{
    size_t idx = 0;
    name.insert(idx, bef);
    name.insert(name.size(), aft);
}

int main()
{
    string name("Tom");
    combin(name, "Jr.", "III");
    cout << name << endl;
}
