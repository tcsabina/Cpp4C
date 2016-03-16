#include <string.h>
#include <iostream>
#include <cstdlib>

const int max_len = 255;

class myString {
    private:
        char *s;
        int  len;
    public:
        myString();
        myString(int n);
        myString(char *p);        
        ~myString();

        void assign(const char *st);
        int length();
        void print();
        void print(int k);
        void reverse();
        myString & operator =(const myString &a);
        friend myString operator +(const myString &a, const myString &b);
};

myString::myString() {
    len = max_len; 
    s   = new char[max_len](); 
}

myString::myString(int n) {
    s   = new char[n+1]; 
    len = n; 
}

myString::myString(char *p) {
    len = strlen(p); 
    s   = new char[len+1];
    strcpy(s,p); 
}

myString::~myString() {
    delete[] s; 
}

void myString::assign(const char *st) {
    strcpy(s, st); 
    len = strlen(st);
}

int myString::length() {
    return len;
}

void myString::print() {
    std::cout << s << "\nLength: " << len << "\n";
}

void myString::print(int k) {
    for (int i = 0; i < k && i < len; i++)
        std::cout << s[i];

    std::cout << "\n";
}

void myString::reverse() {
    char *a, *b, c;
    
    a = s;
    b = a+len-1;
    while (a <= b)
    {
        c = *a;
        *a++ = *b;
        *b-- = c;
    }
}

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
    myString one;

    one.assign("My name is Alan Turing");
    one.print();
//    one.reverse();
    one.print(23);

    return 0;
}

