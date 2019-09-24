#include <memory>
#include <iostream>

using namespace std;

int main()
{
    auto p = make_shared<int>(42);
    auto q(p);
    auto other = make_shared<int> (77);

    cout << "*p = " << *p << " [" << p << "]" << endl;
    cout << "*q = " << *q << " [" << q << "]" << endl;
    cout << "p count = " << p.use_count() << endl;
    cout << "q count = " << q.use_count() << endl;
    cout << "other count = " << other.use_count() << endl;

    p = q;
    cout << "*p = " << *p << " [" << p << "]" << endl;
    cout << "*q = " << *q << " [" << q << "]" << endl;
    cout << "p count = " << p.use_count() << endl;
    cout << "q count = " << q.use_count() << endl;
    cout << "other count = " << other.use_count() << endl;

    p = other;
    cout << "*p = " << *p << " [" << p << "]" << endl;
    cout << "*q = " << *q << " [" << q << "]" << endl;
    cout << "p count = " << p.use_count() << endl;
    cout << "q count = " << q.use_count() << endl;
    cout << "other count = " << other.use_count() << endl;

    return 0;
}
