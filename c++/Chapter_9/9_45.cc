#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void combin(string &name, const string &bef, const string &aft)
{
    auto curr = name.begin();
    curr = name.insert(curr, bef.begin(), bef.end());
    name.append(aft);
}

int main()
{
    string name("Tom");
    combin(name, "Jr.", "III");
    cout << name << endl;
}
