#include <iostream>

const int max_len = 1000;

struct stack {	
    char s[max_len];
    int  top;

    void reset() { top = 0; }
    void push(char c);
    char pop() { return s[--top]; }
    char pop(int n);
    char top_of() { return s[top]; }
    bool empty() { return top == 0; }
    bool full() { return top == (max_len-1); }
};

void stack::push(char c) {
    s[top++] = c;
}

char stack::pop(int n) {
    while (n-- > 1)
        top--;

    return s[top--];
}

void reverse(char* s1, char* s2) {
    stack s;

    s.reset();
    while (*s1) {
        if (!s.full())
            s.push(*s1);

        ++s1;
    }

    while(!s.empty()) {
        *s2 = s.pop();
        ++s2;
    }
}

int main() {
    static char s1[40] = "My name is Tamas Csabina.";
    static char s2[40] = "";

    reverse(s1, s2);
    std::cout << s2 << std::endl;

    return 0;
}

