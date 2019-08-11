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
    vector <int> origin {10, 11, 12, 13};
    vector <int> vec {0, 1};

    //insert at end
    vec.insert(vec.end(), {4, 5, 6});
    print(vec);

    //insert range of iterator
    auto o0 = origin.begin();
    auto o1 = o0 + 1;
    auto o2 = o1 + 1;
    auto o3 = o2 + 1;

    vec.insert(vec.begin() + 1, o0, o2);
    print(vec);
    return 0;
}
