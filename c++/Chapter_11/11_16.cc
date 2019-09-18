#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    map<string, int> tmp {{"first", 7}};
    auto it = tmp.begin();
    cout << it->first << " " << it->second << endl;

    it->second = 0;
    cout << it->first << " " << it->second << endl;
    return 0;
}
