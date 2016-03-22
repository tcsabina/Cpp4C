#include <iostream>
#include <stdlib.h>

class vect {
    int* p;
    int  size;
public:
    int ub;
    vect() { size = 10; p = new int[size]; ub = size-1; }
    vect(int n);
    ~vect() { delete p; }
    int& element(int i);
};

vect::vect(int n) {
    if (n <= 0) {
        std::cerr << "illegal vect size " << n << "\n";
        exit(1);
    }

    size = n;
    p    = new int[size];
    ub   = size-1;
}

int& vect::element(int i) {
    if (i < 0 || i > ub) {
        std::cerr << "illegal vect index " << i << "\n";
        exit(1);
    }

    return p[i];
}

class multi_v {
public:
    vect a, b, c;
    multi_v(int i): a(i), b(i), c(i) { }
};

int main() {
    multi_v a_w_h(5);

    for (int i = 0; i <= a_w_h.a.ub; i++) {
        a_w_h.a.element(i) = 21 + i;
        a_w_h.b.element(i) = 135 + i;
        a_w_h.c.element(i) = 62 + i;
    }

    for (int i = 0; i <= a_w_h.a.ub; i++) {
        std::cout << a_w_h.a.element(i) << " years ";
        std::cout << a_w_h.b.element(i) << " pounds ";
        std::cout << a_w_h.c.element(i) << " inches\n";
    }

    return 0;
}

