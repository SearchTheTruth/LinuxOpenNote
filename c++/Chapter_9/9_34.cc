#include <stdlib.h>

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const auto &src)
{
    cout << "event num =" << src.size() << "=" << endl;
    for (const auto &ev : src) {
        cout << ev << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    vector<int> vi{7, 0, 1, 2, 3};

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2)
            iter = vi.insert(iter, *iter++);
        ++iter;
    }
    print(vi);
    cout << "end!" << endl;
    return 0;
}
