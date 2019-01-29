#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0 ,tCnt = 0;
    char ch;
    /*std::noskipws 标准流中skipws 默认置位,表明读取空白字符时将他们丢弃,使用std::noskipws可以清楚这个标记*/
    while (cin >> std::noskipws >> ch) {
        switch (ch) {
            case 'A':
            case 'a':
                ++aCnt;
                break;
            case 'E':
            case 'e':
                ++eCnt;
                break;
            case 'I':
            case 'i':
                ++iCnt;
                break;
            case 'O':
            case 'o':
                ++oCnt;
                break;
            case 'U':
            case 'u':
                ++uCnt;
                break;
            case ' ':
            case '\n':
            case '\t':
                ++tCnt;
                break;
            default:
                break;
        }
    }

    cout << "A/a: " << aCnt << endl;
    cout << "E/e: " << eCnt << endl;
    cout << "I/i: " << iCnt << endl;
    cout << "O/o: " << oCnt << endl;
    cout << "U/u: " << uCnt << endl;
    cout << " /\\t/\\n: " << tCnt << endl;

    return 0;
}
