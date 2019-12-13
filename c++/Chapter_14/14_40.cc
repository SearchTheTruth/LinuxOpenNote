#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class isShort {
    public:
        bool operator()(const string &l, const string &r) {
            return l.size() < r.size();
        }
};

class beCam {
    public:
        beCam(size_t n) : num(n) {};
        bool operator()(const string &str) {
            return str.size() >= num;
        }
    private:
        size_t num;
};

void elimDups(vector<string> &vecStr)
{
    sort(vecStr.begin(), vecStr.end());
    auto endunique = unique(vecStr.begin(), vecStr.end());
    vecStr.erase(endunique, vecStr.end());
}

void biggest(vector<string> &vecStr, size_t n)
{
    for_each(vecStr.begin(), vecStr.end(), [](const string &ele){cout << ele << " ";});
    cout << endl;
    elimDups(vecStr);
    for_each(vecStr.begin(), vecStr.end(), [](const string &ele){cout << ele << " ";});
    cout << endl;
    stable_sort(vecStr.begin(), vecStr.end(), isShort());
    for_each(vecStr.begin(), vecStr.end(), [](const string &ele){cout << ele << " ";});
    cout << endl;
    auto bigger = find_if(vecStr.begin(), vecStr.end(), beCam(n));
    cout << vecStr.end() - bigger << " words is length than " << n << endl;
    for_each(bigger, vecStr.end(), [](const string &ele){cout << ele << " ";});
    cout << endl;
}

int main()
{
    size_t num;
    string line, word;
    vector<string> tmp;
    if (getline(cin, line)) {
        istringstream istr(line);
        while (istr >> word) {
            tmp.push_back(word);
        }
    }
    cout << "input thrshold" << endl;
    cin >> num;
    cout << "find word length than " << num << endl;
    biggest(tmp, num);
    return 0;
}
