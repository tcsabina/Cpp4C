#include <iostream>

class X {
    char c;
public:
    void init(char b) { c = b; }
    char valc() { return this->c; }
};

int main() {
    X a;

    a.init('b');
    std::cout << a.valc() << "\n";

    return 0;
}
