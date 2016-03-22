#include <iostream>
#include <string.h>

class string {
    char* s;
    int   len;
public:
    string() { s = new char[81]; len = 80; }
    string(int n) { s = new char[n+1]; len = n; }
    string(char* p) { len = strlen(p); s = new char[len+1]; strcpy(s, p); }
    string(string& str);
    ~string() { delete s; }

    void assign(char* str) {strcpy(s, str); len = strlen(str); }
    void print() { std::cout << s << "\n"; }
    void concat(string& a, string& b);
};

string::string(string& str) {
    len = str.len;
    s   = new char[len+1];
    strcpy(s, str.s);
}

void string::concat(string& a, string& b) {
    len = a.len + b.len;
    delete s;
    s = new char[len+1];
    strcpy(s, a.s);
    strcat(s, b.s);
}

int main() {
    char* str = "The wheel that squeaks the loudest\n";
    string a(str), b, author("Josh Billings\n"), both, quote;

    b.assign("Is the one that gets the grease\n");
    both.concat(a, b);
    quote.concat(both, author);
    quote.print();

    return 0;
}

