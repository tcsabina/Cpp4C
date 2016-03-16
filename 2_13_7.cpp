#include <iostream>

int main() {
    char* c;
    char* strg = "ABCD";

    std::cout << "strg is " << strg << "\n";
    c = strg + 1;
    std::cout << "c is " << *c << "\n";
    *c = 'X';
    std::cout << "c is " << *c << "\n";
    std::cout << "strg is " << strg << "\n";
}

