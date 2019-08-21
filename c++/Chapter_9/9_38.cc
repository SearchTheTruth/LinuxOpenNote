#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

void print(const auto &src)
{
    cout << "event num =" << src.size() << "=" << endl;
    for (auto beg = src.begin(); beg != src.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl << "++++++++++++++" << endl;
}

int main()
{
    char ch;
    vector<int> text;
    cout << "text.capacity = " << text.capacity() << " text.size = " << text.size() << endl;
    while (1) {
        while (text.capacity() != text.size())
            text.push_back(1);
        cout << "press Y/y to continue" << endl;
        cin >> ch;
        if (ch != 'Y' && ch != 'y')
            break;
        text.push_back(1);
        cout << "text.capacity = " << text.capacity() << " text.size = " << text.size() << endl;
    }
    return 0;
}
