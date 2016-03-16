#include <iostream>

static union {
    int   j;
    float y;
};

int main() {
    int   i = 1024;
    float x = 1.0;

//    j = i;
    std::cout << y << "\n";
//    y = x;
    std::cout << y << "\n";
    y = 2 * x;
    std::cout << j << "\n";

    return 0;
}

