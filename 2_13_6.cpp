#include <iostream>

char strg[5] = "ABCD";
int main() {
    int i  = 7;
    int* p =&i;
    char* c;

//    c  = *p;
    c  = strg + 1;
    std::cout << c << "\n";
    *c = 'X';
    std::cout << c << "\n";
}

