#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Account {
    public:
        static int countNum;
        Account(const string &initName, double initMoney) : name(initName), money(initMoney) {};
        Account(const string &initName) : Account(initName, 0) {};
        void setRate(const double newRate);
        void displayAccount();
    private:
        static double rate;
        string name;
        double money;
};

double Account::rate = 3.0;
int Account::countNum = 0;

void Account::setRate(const double newRate)
{
    rate = newRate;
}

void Account::displayAccount()
{
    cout << "count num = " << countNum << std::endl;
    cout << name << " " << money << "$ rate " << rate << std::endl;
}

int main()
{
    Account richMan("richMan", 99);
    ++richMan.countNum;

    richMan.displayAccount();

    Account poorMan("poorMan", 0);
    ++Account::countNum;

    poorMan.displayAccount();

    richMan.setRate(2.0);

    richMan.displayAccount();
    poorMan.displayAccount();
    return 0;
}
