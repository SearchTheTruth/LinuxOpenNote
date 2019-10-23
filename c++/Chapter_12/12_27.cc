#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>

using namespace std;
#define FILENAME "txt_12_27.txt"


class QueryResult {
    public:
        QueryResult();

        QueryResult(shared_ptr<vector<string>> textOrig, const string schOrig, set<size_t> lineOrig, int countOrig) :
            text(textOrig), search(schOrig), line(lineOrig), count(countOrig) {};

        QueryResult(shared_ptr<vector<string>> textOrig, const string schOrig, set<size_t> lineOrig) :
            QueryResult(textOrig, schOrig, lineOrig, 0) {};

        void print() {
            cout << search << " occurs " << line.size() << " times" << endl;
            for (auto &pos : line) {
                cout << "(line " << pos + 1 << ") " << (*text)[pos] << endl;
            }
        };
    private:
        shared_ptr<vector<string>> text;
        string search;
        set<size_t> line;
        int count = 0;
};

class TextQuery {
    public:
        TextQuery() : text(make_shared<vector<string>>()), clew(make_shared<map<string, set<size_t>>>()) {};

        TextQuery(ifstream &input) : TextQuery() {
            if (!input)
                throw runtime_error("invaild stream");

            string tmpStr;
            while (input) {
                getline(input, tmpStr);
                text->push_back(tmpStr);
            }
        };

        QueryResult query(const string &search) {
            if (clew->find(search) == clew->end()) {    //do not search before
                //cout << "DBG: START FIND " << search << " IN " << FILENAME << endl;
                set<size_t> line;
                auto pos = text->begin();

                auto findStr = [=](const string &str) -> bool {
                    return string::npos != str.find(search);
                };

                pos = find_if(pos, text->end(), findStr);
                while (pos != text->end()) {
                    //cout << "DBG: FIND ELEMENT" << endl;
                    line.insert(pos - text->begin());
                    ++pos;
                    pos = find_if(pos, text->end(), findStr);
                }
                clew->insert(make_pair(search, line));
            }
            return QueryResult(text, search, (*clew)[search]);
        };

    private:
        shared_ptr<vector<string>> text;
        shared_ptr<map<string, set<size_t>>> clew;
        int count = 0;
};

int main()
{
    ifstream fs(FILENAME);
    if (!fs)
        throw runtime_error("can't open file");

    TextQuery doc(fs);
    while (1) {
        cout << "input word you want search in " << FILENAME << endl;
        cout << "q for exit" << endl;
        string str;
        cin >> str;
        if (str == "q")
            break;
        QueryResult docResult = doc.query(str);
        docResult.print();
    }
    return 0;
}

/* debug version
auto findStr = [=](const string &str) -> bool {
    cout << "DBG: FIND " << search << " IN " << str << endl;
    auto ret = str.find(search);
    bool result;
    if (ret == string::npos)
        result = false;
    else
        result = true;
    cout << "DBG: FIND(" << result << ")" << endl;
    return result;
};
*/

