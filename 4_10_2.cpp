#include <iostream>

const int modulus = 60;

class mod_int {
    int v;
public:
    mod_int() { v = 0; }
    mod_int(int i) { v = i % modulus; }
    void assign(int i) { v = i % modulus; }
    void print() { std::cout << v; }
    void add_to(int i) { std::cout << "adding " << i << " to " << v << "\n"; v += i; v %= modulus; }
};

int main() {
    int seconds = 400;
    mod_int z(seconds);
    mod_int s1, s2;

    std::cout << seconds << " seconds equals " << seconds / 60 << " minutes ";
    z.print();
    std::cout << " seconds\n";

    z.add_to(20);
    std::cout << seconds << " seconds equals " << seconds / 60 << " minutes ";
    z.print();
    std::cout << " seconds\n";

    return 0;
}

