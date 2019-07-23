#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::istream; using std::ostream;

#include <sstream>
using std::ostringstream; using std::istringstream;


// members are public by default
struct PersonInfo {
	string name;
	vector<string> phones;
};


// we'll see how to reformat phone numbers in chapter 17
// for now just return the string we're given
string format(const string &s) { return s; }

bool valid(const string &s)
{
	// we'll see how to validate phone numbers
	// in chapter 17, for now just return true
	return true;
}


vector<PersonInfo> getData(istream &is)
{
    string line;
    string num;
    vector <PersonInfo> peoples;

    while (getline(is, line)) {
        struct PersonInfo single;
        istringstream istr(line);
        if (istr >> single.name) {
            while (istr >> num) {
                single.phones.push_back(num);
            }
        }
        peoples.push_back(single);
    }
    return peoples;
}


int process(ostream &os, vector<PersonInfo> peoples)
{
    for (const auto &entry : peoples) {
        ostringstream bad_num, format_str;
        for (const auto &num : entry.phones) {
            if (!valid(num)) {
                bad_num << num << " ";
            } else {
                format_str << format(num) << " ";
            }
        }

        if (bad_num.str().empty()) {
            os << "format: " << entry.name << " " << format_str.str() << endl;
        } else {
            cerr << "bad_num: " << entry.name << " " << bad_num.str() << endl;
        }
    }

    return 0;
}

int main ()
{
    process(cout, getData(cin));
    return 0;
}
