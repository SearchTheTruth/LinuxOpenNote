#include <iostream>
#include <string>

using namespace std;

class printBox {
    public:
        string operator()(istream &is) {
            string line;
            if (!getline(is, line))
                line.clear();
            return line;
        };
};


int main ()
{
    printBox worker;
    cout << worker(cin) << endl;
}
