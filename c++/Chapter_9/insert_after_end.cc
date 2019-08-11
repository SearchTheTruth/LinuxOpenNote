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
    vector <int> vec {0, 1};

    vec.insert(vec.end(), {4, 5, 6});

    print(vec);
    return 0;
}
