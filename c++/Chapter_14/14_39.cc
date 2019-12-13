#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class equalLenth {
    public:
        equalLenth(size_t n) : threshold(n) {};
        bool operator()(const string& str) {
            return str.size() == threshold;
        }
    private:
        size_t threshold;
};


int main()
{
    string line;
    vector<string> context;
    int ret = 0;
    while (getline(cin, line)) {
        string word;
        istringstream istr(line);
        while(istr >> word) {
            context.push_back(word);
        }
    }
    for (int i = 1; i < 10; ++i) {
        int count = 0;
        for (auto &ele : context) {
            equalLenth worker(i);
            if (worker(ele))
                ++count;
        }
        ret += count;
        cout << "lenth: " << i << " words: " << count << endl;
    }
    cout << "lenth larger than 9, " << " words: " << context.size() - ret << endl;
    return 0;
}
