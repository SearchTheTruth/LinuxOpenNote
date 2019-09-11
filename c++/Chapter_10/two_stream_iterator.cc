#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> a(cin), b(cin), eof;

    cout << "a " << *a++ << endl;
    cout << "b " << *b << endl;
    cout << "a " << *a << endl;
    return 0;
}
