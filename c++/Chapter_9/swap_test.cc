#include <array>
using std::array;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(auto &beg, auto &end)
{
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec_1 {1, 2, 3};
    vector<int>::iterator vps = vec_1.begin();
    vector<int>::iterator vpe = vec_1.end();
    vector<int> vec_2 {4, 5, 6};
    int *p1 = &vec_1[0];
    cout << "vec_1[0] = " << *p1 << endl;
    vps++;
    vpe--;

    print(vps, vpe);
    cout << "after swap!!" << endl;
    swap(vec_1, vec_2);
    print(vps, vpe);
    cout << "vec_1[0] = " << *p1 << endl;

    array<int, 3> arr_1 {11, 12, 13};
    array<int, 3> arr_2 {14, 15, 16};
    array<int, 3>::iterator aps = arr_1.begin();
    array<int, 3>::iterator ape = arr_1.end();
    int *a1 = &arr_1[0];
    cout << "arr_1[0] = " << *a1 << endl;

    print(aps, ape);
    cout << "after swap!!" << endl;
    swap(arr_1, arr_2);
    print(aps, ape);
    cout << "arr_1[0] = " << *a1 << endl;

    return 0;
}
