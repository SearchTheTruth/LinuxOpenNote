#include "Blob.h"
#include "BlobPtr.h"

int main()
{
    Blob<int> iblob{0, 1, 2};
    BlobPtr<int> bptr(iblob);
    cout << *++bptr << endl;
    cout << iblob.back() << endl;
    return 0;
}
