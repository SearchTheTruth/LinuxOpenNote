#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Point {
    public:
        Point(string str) : idx(str) {
            cout << "dir init str." << str << endl;
        };
        Point(const Point& org) : idx(org.idx) {
            cout << "copy org." << org.idx << endl;
        };
    private:
        string idx;
};


Point global("global");

Point foo_bar(Point arg)
{
    Point equal("equal");
    Point local = arg, *heap = new Point(global);
    *heap = equal;
    Point pa[2] = {local, *heap};
    return *heap;
}

int main()
{
    Point infuc("infuc");
    Point ret = foo_bar(infuc);
    return 0;
}
