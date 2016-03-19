#include <iostream>

const int max_len = 1000;

class deque {
    char s[max_len];
    int  bottom;
    int  top;

public:
    void reset() { top = bottom = max_len / 2; }
    void push_t(char c);
    void push_b(char c);
    char pop_t();
    char pop_b();
    void print();
};

void deque::push_t(char c) {
    s[top++] = c;
}

void deque::push_b(char c) {
    s[--bottom] = c;
}

char deque::pop_t() {
    return s[--top];
}

char deque::pop_b() {
    return s[bottom++];
}

void deque::print() {
    for (int i = bottom; i < top; i++)
        std::cout << s[i];

    std::cout << "\n";
}

int main() {
    deque d;

    d.reset();
    d.push_t('a');
    d.push_t('b');
    d.push_b('1');
    d.push_b('2');
    d.print();
    d.pop_t();
    d.print();
    d.pop_b();
    d.print();

    return 0;
}

