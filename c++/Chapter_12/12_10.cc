#include <memory>
#include <iostream>

using namespace std;

void process(shared_ptr<int> p)
{
    cout << "process == " << endl;
    cout << *p  << " usecount = " << p.use_count() << endl;
    return;
}

int main()
{
    shared_ptr<int> org(new int(42));

    process(shared_ptr<int> (org));
    cout << "main == " << endl;
    cout << *org  << " usecount = " << org.use_count() << endl;

    process(shared_ptr<int> (org.get())); //这句结束后,org指向的对象实际已经被释放掉了
    cout << "main == " << endl;
    cout << *org  << " usecount = " << org.use_count() << endl;
    return 0;
}
