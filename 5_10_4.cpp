#include <iostream>
#include <stdlib.h>

class matrix;

class vect {
    int* p;
    int size;
    friend vect mpy(vect& v, matrix& m);
    friend vect add(vect& v, matrix& m);
public:
    int ub;
    vect() { size = 10; p = new int[size]; ub = size-1; }
    vect(int n);
    ~vect() { delete p; }
    int& element(int i);
};

class matrix {
    int** p;
    int s1, s2;
    friend vect mpy(vect& v, matrix& m);
    friend vect add(vect& v, matrix& m);
public:
    int   ub1, ub2;
    matrix(int d1, int d2);
    ~matrix();
    int& element(int i, int j);
};

matrix::matrix(int d1, int d2) {
    if (d1 < 0 || d2 < 0) {
        std::cerr << "illegal matrix size " << d1 << " by " << d2 << "\n";
        exit(1);
    }

    s1 = d1;
    s2 = d2;
    p  = new int*[s1];
    for (int i = 0; i < s1; i++)
        p[i] = new int[s2];

    ub1 = s1 - 1;
    ub2 = s2 - 1;
}

matrix::~matrix() { 
    for (int i = 0; i < ub1; i++)
        delete p[i];

    delete p;
}

int& matrix::element(int i, int j) {
    if (i < 0 || i > ub1 || j < 0 || j > ub2) {
        std::cout << "illegal matrix index " << ub1 << ", " << ub2 << "\n";
        exit(1);
    }

    return p[i][j];
}

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

vect mpy(vect& v, matrix& m) {
    if (v.size != m.s1) {
        std::cerr << "multiply failed: sizes incorrect " << v.size << " and " << m.s1 << "\n";
        exit(1);
    }

    vect ans(m.s2);
    for (int i = 0; i <= m.ub2; i++) {
        ans.p[i] = 0;
        for (int j = 0; j <= m.ub1; j++) {
            ans.p[i] += v.p[j] * m.p[j][i];
        }
    }

    return ans;
}

vect add(vect& v, matrix& m) {
    if (v.size != m.s1) {
        std::cerr << "multiply failed: sizes incorrect " << v.size << " and " << m.s1 << "\n";
        exit(1);
    }

    vect ans(m.s2);
    for (int i = 0; i <= m.ub2; i++) {
        ans.p[i] = 0;
        for (int j = 0; j <= m.ub1; j++) {
            ans.p[i] += v.p[j] + m.p[j][i];
            std::cout << "ans.p[" << i << "]=" << ans.p[i] << "(" << v.p[j] << "+" << m.p[j][i] << ")\n";
        }
    }

    return ans;
}

int main() {
    vect v(2);
    matrix m(2, 2);

    v.element(0)    = 1;
    v.element(1)    = 2;
    m.element(0, 0) = 1;
    m.element(0, 1) = 2;
    m.element(1, 0) = 3;
    m.element(1, 1) = 4;
//    mpy(v, m);

//    std::cout << "m[0][0] = " << m.element(0, 0) << "\n";
    vect v2 = add(v, m);
    std::cout << "v2[0] = " << v2.element(0) << "\n";

    return 0;
}

