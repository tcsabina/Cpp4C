#include <iostream>

class B {
public:
    int          i;
    B() { i = 0; }
    virtual void print_i() { std::cout << i << " inside B\n"; }
};

class D1 : public B {
public:
    void print_i() { std::cout << i << " inside D1 B::i is " << B::i << "\n"; }
};

class D2 : public B {
public:
    int  i;
    void print_i() { std::cout << i << " inside D2 B::i is " << B::i << "\n"; }
};

int main() {
    B  b;
    B* pb = &b;
    D1 d1;
    D2 d2;

    d2.i = 3;
    d1.i = 2;
    b.i  = 1;
    pb->print_i();
    pb = &d1;
    pb->print_i();
    pb = &d2;
    pb->print_i();

    return 0;
}

