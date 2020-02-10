#ifndef __TEXTQUERY_H
#define __TEXTQUERY_H
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>
#include "DebugDelete.h"

using namespace std;

class QueryResult {
    public:
        QueryResult();

        QueryResult(shared_ptr<vector<string>> textOrig, const string schOrig, set<size_t> lineOrig, int countOrig) :
            text(textOrig), search(schOrig), line(lineOrig), count(countOrig) {};

        QueryResult(shared_ptr<vector<string>> textOrig, const string schOrig, set<size_t> lineOrig) :
            QueryResult(textOrig, schOrig, lineOrig, 0) {};

        shared_ptr<vector<string>> getfile() const {return text;}
        set<size_t>::iterator begin() { return line.begin(); }
        set<size_t>::iterator end() { return line.end(); }
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
        typedef vector<string>::size_type line_no;
        TextQuery() : text(make_shared<vector<string>>()),\
                      clew(make_shared<map<string, set<size_t>>>()) {
                          shared_ptr<vector<string>> tmp_text(new vector<string>, DebugDelete());
                          text = tmp_text;
                          shared_ptr<map<string, set<size_t>>> tmp_clew(new map<string, set<size_t>>, DebugDelete());
                          clew = tmp_clew;
                      };

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

#endif
