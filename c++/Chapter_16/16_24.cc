#include "Blob.h"
#include "BlobPtr.h"
#include <vector>

using namespace std;

int main()
{
    vector<string> vs{"a", "b", "c"};
    int ia[] = {0, 1, 2};

    Blob<int> ib(begin(ia), end(ia));
    Blob<string> sb(vs.begin(), vs.end());

    cout << ib.back() << endl;
    cout << sb.back() << endl;
    return 0;
}
