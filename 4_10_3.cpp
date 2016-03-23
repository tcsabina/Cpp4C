#include <iostream>

class A {
    int xx;
public:
    A(int n) { xx = n; std::cout << "A(int " << n << ") called\n"; }
    A(double y) { xx = y + 0.5; std::cout << "A(double " << y << ") called\n"; }
    A() { xx = 0; std::cout << "A() called\n"; }
    ~A() { std::cout << "~A() called. A::xx = " << xx << "\n"; }
};

int main() {
    std::cout << "enter main\n";
    int x = 14;
    double y = 17.3;
    A z(11), zz(11.5), zzz(0);
    A d[5];

    std::cout << "\n";
    zzz = A(x);
    zzz = A(y);
    std::cout << "exit main\n";

    return 0;
}
