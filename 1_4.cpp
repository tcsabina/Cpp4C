#include <string.h>
#include <iostream>

const int max_len = 255;

class myString {
    private:
        char s[max_len];
        int  len;
    public:
        void assign(char *st) { strcpy(s, st); len = strlen(st); }
        int length() { return len; }
        void print() { std::cout << s << "\nLength: " << len << "\n"; }
};

int main() {
    myString one, two;
    char three[40] = {"My name is Charles Babbage."};

    one.assign("My name is Alan Turing.");
    two.assign(three);
    std::cout << three;
    std::cout << "\nLength: " << strlen(three) << "\n";
    if (one.length() <= two.length())
        one.print();
    else
        two.print();

    return 0;
}
