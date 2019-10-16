#include <memory>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    allocator<string> box;
    auto p = box.allocate(5);
    const auto start = p;
    string tmp;
    while (cin >> tmp && (p - start) < 5) {
        box.construct(p++, tmp);
    }
    cout << "size = " << p - start << endl;
    for (auto idx = start; idx < p; ++idx) {
        cout << *idx << endl;
    }

    while (start != p) {
        box.destroy(--p);
    }
    box.deallocate(p, 5);
    return 0;
}
