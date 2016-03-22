#include <iostream>
#include <stdlib.h>

class matrix {
    int** p;
    int   s1, s2;
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

int main() {

    return 0;
}

