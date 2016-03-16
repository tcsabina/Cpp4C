#include <iostream>

static union {
    int    i;
    char   c[4];
    double w;
};

int main() {
    int i = 65;

    std::cout << c[1] << "\n";

    return 0;
}

