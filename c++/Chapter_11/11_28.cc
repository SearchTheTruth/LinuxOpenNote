#include <map>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<int>> tmp;
    map<string, vector<int>>::iterator it = tmp.find("key");
    return 0;
}
