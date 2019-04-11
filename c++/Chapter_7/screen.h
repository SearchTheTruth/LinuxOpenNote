#ifndef _SCREEN_H
#define _SCREEN_H

#include <string>

class screen {
    public:
        typedef std::string::size_type pos;
        screen() = default;
        screen(pos &r, pos &c, char &ch):
            length(r), height(c), content(r*c, ch) {};
        char get() const {return content(cursor)};
    private:
        pos cursor = 0;
        pos height = 0, length = 0;
        std::string content;
};


#endif
