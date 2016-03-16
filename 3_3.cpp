#include <iostream>

const int max_len = 1000;

struct stack {	
    char s[max_len];
    int  top;
};

void reset(stack* stk) {
    stk->top = 0;
}

void push(char c, stack* stk) {
    stk->s[stk->top] = c;
    ++stk->top;
}

char pop(stack* stk) {
    return stk->s[--stk->top];
}

char top(stack* stk) {
    return stk->s[stk->top];
}

bool empty(stack* stk) {
    return stk->top == 0;
}

bool full(stack* stk) {
    return stk->top == max_len-1;
}

int main() {
    stack       s;
    static char str[40] = "My name is Tamas Csabina.";
    int         i = 0;

    std::cout << str << std::endl;
    reset(&s);
    while (str[i]) {
        if (!full(&s))
            push(str[i++], &s);
    }

    while (!empty(&s)) {
        std::cout << pop(&s);
    }

    std::cout << std::endl;

    return 0;
}
