#include <iostream>
#include <stdlib.h>

class vect {
    int* p;
    int size;
public:
    vect();
    vect(int n);
    vect(vect& v);
    vect(int a[], int n);
    ~vect();
    int ub() { return size - 1; }
    int& operator [](int i);
    vect& operator =(vect&v );
    vect operator +(vect& v);
};

class vect_bnd : public vect {
    int l_bnd;
    int u_bnd;
public:
    vect_bnd();
    vect_bnd(int lb, int ub);
    int& operator [](int);
    int ub() { return u_bnd; }
    int lb() { return l_bnd; }
};

vect::vect() {
    size = 10;
    p    = new int[size];
}

vect::vect(int n) {
    if (n <= 0) {
        std::cerr << "illegal vect size: " << n << "\n";
        exit(1);
    }

    size = n;
    p    = new int[size];
}

vect::vect(vect& v) {
    size = v.size;
    p    = new int[size];
    for (int i = 0; i < size; i++) {
        p[i] = v.p[i];
    }
}

vect::vect(int a[], int n) {
    if (n <= 0) {
        std::cerr << "illegal vect size: " << n << "\n";
        exit(1);
    }

    size = n;
    p    = new int[size];
    for (int i = 0; i < size; i++) {
        p[i] = a[i];
    }
}

vect::~vect() {
    delete []p;
}

int& vect::operator [](int i) {
    if (i < 0 || i > ub()) {
        std::cerr << "illegal vect size: " << i << "\n";
        exit(1);
    }

    return p[i];
}

vect& vect::operator =(vect& v) {
    int s = size < v.size ? size : v.size;

    if (v.size != size) {
        std::cerr << "copying different size arrays " << size << " and " << v.size << "\n";
        exit(1);
    }

    for (int i = 0; i < s; i++) {
        p[i] = v.p[i];
    }

    return *this;
}

vect vect::operator +(vect& v) {
    int s = size < v.size ? size : v.size;
    vect sum(s);

    if (v.size != size) {
        std::cerr << "adding different size arrays " << size << " and " << v.size << "\n";
        exit(1);
    }

    for (int i = 0; i < s; i++) {
        sum.p[i] = p[i] + v.p[i];
    }

    return sum;
}

vect_bnd::vect_bnd() : vect(10) {
    l_bnd = 0;
    u_bnd = 0;
}

vect_bnd::vect_bnd(int lb, int ub) : vect(ub - lb + 1) {
    l_bnd = lb;
    u_bnd = ub;
}

int& vect_bnd::operator [](int i) {
    if (i < l_bnd || i > u_bnd) {
        std::cerr << "index out of range: " << i << "\n";
        exit(1);
    }

    return vect::operator[](i - l_bnd);
}

int main() {
    vect_bnd s(-5, 5);

    for (int i = s.lb(); i <= s.ub(); i++) {
        s[i] = i;
        std::cout << i << " ";
    }

    std::cout << "\n";

    return 0;
}

