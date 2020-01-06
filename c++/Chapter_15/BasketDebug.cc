#include <set>
#include <iostream>
#include <string>
#include <memory>

using namespace std;
class Quote {
    public:
        int getnum() {
            return num;
        }
    private:
        int num;
};

class basket {
    public:
        void add_item(const shared_ptr<Quote> &b) {
            setQuo.insert(b);
        }
    private:
        static bool compare(const shared_ptr<Quote> &l, const shared_ptr<Quote> &r) {
            return l->getnum() < r->getnum();
        }
        multiset<shared_ptr<Quote>, decltype(compare)*> setQuo{compare};
};


int main()
{
    cout << "start" << endl;
}
