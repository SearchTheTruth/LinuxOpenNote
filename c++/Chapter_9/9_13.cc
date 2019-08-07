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
    vector<int> vec_int {1, 2, 3, 4};
    list<int> list_int {5, 6, 7, 8};

    vector<double> vec_dou_1(vec_int.begin(), vec_int.end());
    print(vec_dou_1);

    vector<double> vec_dou_2(list_int.begin(), list_int.end());
    print(vec_dou_2);

    return 0;
}
