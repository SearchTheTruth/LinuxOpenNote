#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string &transform(const string &key, const map<string, string> &rules)
{
    auto pos = rules.find(key);
    if (pos != rules.end()) {
        return pos->second;
    } else {
        return key;
    }
}

map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> rules;
    string key, value, tmp;

    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1) {
            value = value.substr(1);    //去除空格
            rules[key] = value;
        } else {
            throw runtime_error("no rules for key: " + key);
        }
    }
    return rules;
}

void transfer_word(ifstream &map_file, ifstream &input)
{
    map<string, string> rules = buildMap(map_file);
    string line, word;
    bool firstword;

    while (getline(input, line)) {
        istringstream wordstream(line);
        firstword = true;
        while (wordstream >> word) {
            word = transform(word, rules);
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << word;
        }
        cout << endl;
    }
}

int main()
{
    ifstream map("rules");
    ifstream input("text");

    transfer_word(map, input);

    return 0;
}
