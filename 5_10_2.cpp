#include <iostream>
#include <math.h>

double sqrt(double);

class complex {
    double real, imag;
public:
    complex(double r) { real = r; imag = 0; }

    void assign(double r, double i) { real = r; imag = i; }
    void print() { std::cout << real << " + " << imag << "i"; }
//    operator double() { return(sqrt(real*real + imag*imag)); }
    operator double() { return real; }
};

inline int     greater(int i, int j) { return (i > j ? i : j); }
inline double  greater(double x, double y) { return (x > y ? x : y); }
inline complex greater(complex w, complex z) { return (w > z ? w : z); }

int main() {
    int i1 = 10, i2 = 5;
    double d1 = 7.0, d2 = 14.5;
    complex c1(0), c2(0), cmax(0);

    c1.assign(d1, d2);
    c2.assign(i1, i2);
//    std::cout << "1) compare " << i1 << " and " << i2 << ". greater is " << greater(i1, i2) << "\n";
//    std::cout << "2) compare " << d2 << " and " << i1 << ". greater is " << greater(d2, double(i2)) << "\n";
//    std::cout << "3) compare " << d2 << " and "; c2.print(); std::cout << ". greater is " << greater(d2, double(c2)) << "\n";
    cmax = greater(c1, c2);
//    std::cout << "4) compare "; c1.print(); std::cout << " and "; c2.print(); std::cout << ". greater is "; cmax.print(); std::cout << "\n";
    std::cout << "c1 = "; c1.print(); std::cout << "\n";
    std::cout << "converted to double = " << double(c1) << "\n";

    return 0;
}

