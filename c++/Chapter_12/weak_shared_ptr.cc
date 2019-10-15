#include <memory>
#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> sp = make_shared<int>(2);
    weak_ptr<int> wsp(sp);

    cout << "use_cout: " << sp.use_count() << endl;
    //cout << "sp: " << *sp << "wsp: " << *wsp << endl;
    cout << "sp: " << *sp << endl;

    return 0;
}
