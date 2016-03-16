#include <string.h>
#include <iostream>
#include <cstdlib>

const int max_len = 255;

class myString {
    private:
        char *s;
        int  len;
    public:
        myString() { len = max_len; s = new char[max_len](); }
        myString(int n) { s = new char[n+1]; len = n; }
        myString(char *p) { len = strlen(p); s = new char[len+1]; strcpy(s,p); }        
        ~myString() { delete[] s; }

        void assign(const char *st) { strcpy(s, st); len = strlen(st); }
        int length() { return len; }
        void print() { std::cout << s << "\nLength: " << len << "\n"; }
        myString & operator =(const myString &a);
        friend myString operator +(const myString &a, const myString &b);
};

myString & myString::operator =(const myString &a) {
    len = a.len;
    strcpy(s, a.s);

    return *this;
}

myString operator +(const myString &a, const myString &b) {
    char temp[a.len + b.len + 1];

    strcpy(temp, a.s);
    strcat(temp, b.s);

    return myString(temp);
}

int main() {
    myString one, two;
    myString both;
    char three[40] = {"My name is Charles Babbage."};

    one.assign("My name is Alan Turing.");
    two.assign(three);

    if (one.length() > two.length())
        one.print();
    else
        two.print();

    both = one;
    both.print();
    both = one + two;
    both.print();

    return 0;
}
