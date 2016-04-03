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

int main() {

    return 0;
}

