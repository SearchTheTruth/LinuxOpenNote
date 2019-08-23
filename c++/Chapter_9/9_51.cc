#include <string>
using std::string;

#include <array>
using std::array;

#include <iostream>
using std::cout; using std::cin; using std::endl;

class date {
    public:
        date(string input);
        void showdate();
    private:
        unsigned year;
        unsigned month;
        unsigned day;
};

date::date(string input)
{
    size_t curr;
    string num("0123456789");
    array<string, 12> monStr {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    cout << "input = " << input << endl;
    curr = input.find_first_not_of(num);
    cout << "no num pos = " << curr << " , string is = " << string(input, 0, curr) << endl;
    if (curr != 0) {
        month = stoi(input.substr(0, curr));
        ++curr;
        curr = input.find_first_of(num, curr);
    } else {
        for(int i = 0; i < monStr.size(); ++i) {
            if (monStr[i] == input.substr(0, 3))
                month = i + 1;
        }
        curr = input.find_first_of(num);
        cout << "curr = " << curr << " , month = " << month << endl;
    }

    input = input.substr(curr);
    cout << "trim = " << input << endl;
    curr = input.find_first_not_of(num);
    cout << "no num pos = " << curr << " , string is = " << string(input, 0, curr) << endl;
    day = stoi(input.substr(0, curr));

    curr = input.find_first_of(num, curr);
    input = input.substr(curr);
    year = stoi(input);
}

void date::showdate()
{
    cout << year << ": " << month << ": " << day << endl;
}

int main()
{
    string input;

    getline(cin, input);
    date record(input);
    record.showdate();

    return 0;
}
