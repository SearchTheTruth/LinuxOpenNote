#include <algorithm>
using std::sort;
using std::stable_sort;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include "../Chapter_7/sales_data.h"

bool compareIsbn(const sales_data &bk1, const sales_data &bk2)
{
    return bk1.isbn() < bk2.isbn();
}

int main()
{
    vector<sales_data> books;
    books.push_back(sales_data("doller"));
    books.push_back(sales_data("apple"));
    books.push_back(sales_data("cat"));
    for (const auto &bk : books) {
        print(cout, bk);
    }

    cout << endl << "sort bookId" << endl;
    sort(books.begin(), books.end(), compareIsbn);
    for (const auto &bk : books) {
        print(cout, bk);
    }
    cout << endl;

    return 0;
}
