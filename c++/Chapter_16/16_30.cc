#include "Blob_Myshared.h"

int main()
{
    Blob<int> iblob{0, 1, 2};
    cout << iblob.back() << endl;
    return 0;
}
