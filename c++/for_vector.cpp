#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	int i ;
	vector<int> tmp;

	for(i = 0; i < 10; i++)
	{
		tmp.push_back(i);
	}

	for(auto &v : tmp)
		cout << v << endl;
/*
	for(auto p = tmp.begin(); p != tmp.end(); p++)
	{
		cout << *p <<endl;
	}
*/
/*
	int p;
	for(p = 0; p < 10; p++)
		cout << tmp[p] << endl;
*/
}
