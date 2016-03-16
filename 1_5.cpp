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
        friend myString operator +(myString &a, myString &b);
};

myString operator +(myString &a, myString &b) {
    myString temp;

    temp.assign(a.s);
    if (a.len + b.len < max_len)
        temp.assign(strcat(temp.s, b.s));
    else
        std::cerr << "Max length exceeded.\n";
    
    return temp;
}

void print(char *c) {
    std::cout << c << "\nLength: " << strlen(c) << "\n";
}

int main() {
    myString one, two, both;
    char three[40] = {"My name is Charles Babbage."};

    one.assign("My name is Alan Turing.");
    two.assign(three);
    print(three);
    if (one.length() <= two.length())
        one.print();
    else
        two.print();

    both = one + two;
    both.print();

    return 0;
}
