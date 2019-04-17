#ifndef _SCREEN_H
#define _SCREEN_H

#include <iostream>
#include <string>

class Screen {
    public:
        typedef std::string::size_type pos;

        Screen() = default;
        Screen(pos r, pos c): length(r), height(c), content(r*c, ' ') {};
        Screen(pos r, pos c, char ch):
            length(r), height(c), content(r*c, ch) {};

        char get() const {return content[cursor];};
        Screen &move(pos r, pos c);
        Screen &set(char ch);
        Screen &set(pos r, pos c, char ch);
        Screen &display(std::ostream &os);
        const Screen &display(std::ostream &os) const;
    private:
        pos cursor = 0;
        pos height = 0, length = 0;
        std::string content;

        void do_display(std::ostream &os) const {
            pos len = 0;
            for (auto &ch : content) {
                std::cout << ch << " ";
                ++len;
                if (len == length) {
                    len = 0;
                    std::cout << "\n";
                }
            }
        };
};

inline Screen &Screen::move(pos r, pos c)
{
    cursor = (r - 1) * length + c;
    return *this;
}

inline Screen &Screen::set(char ch)
{
    content[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    content[r * length + c] = ch;
    return *this;
}

inline Screen &Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}

inline const Screen &Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}
#endif
