#include <iostream>
#include <stdlib.h>

const int max_len = 1000;

struct stack {	
    char s[max_len];
    int  top;

    void reset() { top = 0; }
    void push(char c);
    char pop();
    char pop(int n);
    char top_of() { return s[top]; }
    bool empty() { return top == 0; }
    bool full() { return top == (max_len-1); }
};

void stack::push(char c) {
    if (full()) {
        std::cerr << "stack full!\n";
        exit(1);
    }

    s[top++] = c;
}

char stack::pop() {
    if (top == 0) {
        std::cerr << "stack empty!\n";
        exit(1);
    }

    return s[--top]; 
}

char stack::pop(int n) {
    while (n-- > 1)
        top--;

    return s[top--];
}

int main() {
    stack       s;
    static char str[40] = "My name is Tamas Csabina.";
    int         i = 0;

    std::cout << str << std::endl;
    s.reset();
    while (str[i]) {
        if (!s.full())
            s.push(str[i++]);
    }

    while (!s.empty()) {
        std::cout << s.pop();
    }

    std::cout << std::endl;

    while (1)
     s.push('1');

    return 0;
}

