#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0 ,tCnt = 0, ffCnt = 0, fiCnt = 0, flCnt = 0;
    char ch, prech = 0;
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
                if (prech == 'f')
                    ++fiCnt;
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
            case 'f':
                if (prech == 'f')
                    ++ffCnt;
                break;
            case 'l':
                if (prech == 'f')
                    ++flCnt;
                break;
            default:
                break;
        }
        prech = ch;
    }

    cout << "A/a: " << aCnt << endl;
    cout << "E/e: " << eCnt << endl;
    cout << "I/i: " << iCnt << endl;
    cout << "O/o: " << oCnt << endl;
    cout << "U/u: " << uCnt << endl;
    cout << " /\\t/\\n: " << tCnt << endl;
    cout << "ff: " << ffCnt << endl;
    cout << "fi: " << fiCnt << endl;
    cout << "fl: " << flCnt << endl;

    return 0;
}
