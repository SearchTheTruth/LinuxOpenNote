#include <memory>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

char *append(const char *c1, const char *c2, char *dst)
{
    size_t index = 0;
    size_t pos = 0;
    while (c1[index] != '\0') {
        dst[pos++] = c1[index++];
    }
    index = 0;
    while (c2[index] != '\0') {
        dst[pos++] = c2[index++];
    }
    return dst;
}

int main()
{
    const char *c1 = "Hello", *c2 = "World";
    size_t len = strlen(c1) + strlen(c2) + 1;
    char *cdst = new char[len]();


    cout << "c1 = " << c1 << " c2 = " << c2 << endl;
    cout << "after append str = " << append(c1, c2, cdst) << endl;

    memset(cdst, 0, len);
    string s1(c1), s2(c2);
    strcpy(cdst, (s1 + s2).c_str());
    cout << "after append str = " << cdst << endl;
    delete []cdst;
    return 0;
}
