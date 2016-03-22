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

int main() {
    vect a(10), b(5);

    a.element(1) = 5;
    b.element(1) = a.element(1) + 7;
    std::cout << a.element(1) - 2 << "\n";

    return 0;
}

