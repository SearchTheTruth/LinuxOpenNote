#include <iostream>
#include <string>
#include <vector>


using namespace std;

class printBox {
    public:
        string operator()(istream &is) {
            string line;
            while (getline(is, line))
                buff.push_back(line);
            return buff.back();
        };
    private:
        vector<string> buff;
};


int main ()
{
    printBox worker;
    cout << worker(cin) << endl;
}
