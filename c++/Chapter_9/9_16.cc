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

/*0 equal, 1 list > vector, -1 list < vector*/
int large(const list<int> &list_int, const vector<int> &vec_int)
{
    int result = 0;
    auto list_beg = list_int.begin();
    auto vec_beg = vec_int.begin();
    for (;
            list_beg != list_int.end() && vec_beg != vec_int.end();
            ++list_beg, ++vec_beg) {
        if (*list_beg == *vec_beg)
            continue;
        else if (*list_beg > *vec_beg) {
            result = 1;
            break;
        } else {
            result = -1;
            break;
        }
    }
    if (!result) {
        if (list_int.size() > vec_int.size())
            result = 1;
        else if (list_int.size() < vec_int.size())
            result =-1;
    }

    return result;
}

int main()
{
    list<int> list1 {1, 2, 3, 4};
    vector<int> vec1 {1, 2};
    vector<int> vec2 {9};
    vector<int> vec3 {1, 2, 3, 4};
    vector<int> vec4 {1, 2, 3, 4, 5};

    print(list1);
    print(vec1);
    cout << large(list1, vec1) << endl << endl;


    print(list1);
    print(vec2);
    cout << large(list1, vec2) << endl << endl;

    print(list1);
    print(vec3);
    cout << large(list1, vec3) << endl << endl;

    print(list1);
    print(vec4);
    cout << large(list1, vec4) << endl << endl;

    return 0;
}

