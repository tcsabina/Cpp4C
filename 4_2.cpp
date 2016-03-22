#include <iostream>

class stack {
    char* s;
    int   max_len;
    int   top;
public:
    stack() { s = new char[100]; max_len = 100; top = 0; }
    stack(int size, char str[]);
    stack(int size) { s = new char[size]; max_len = size; top = 0; }
    ~stack() { delete s; }

    void reset() { top = 0; }
    void push(char c) { s[top++] = c; }
    char pop() { return s[--top]; }
    char top_of() { return s[top]; }
    bool empty() { return top == 0; }
    bool full() { return top == (max_len-1); }
};

stack::stack(int size, char str[]) {
    int i;

    s       = new char[size];
    max_len = size;
    for (i = 0; i < max_len && str[i] != 0; i++)
        s[i] = str[i];

    top = i;
}

int main() {



    return 0;
}

