#include <iostream>

const float pi = 3.14159;

inline float circum(float rad) { return 2 * rad * pi; }
inline float area(float rad) { return rad * rad * pi; }

int main() {
    float r;

    while (true) {
        std::cout << "\nEnter radius: ";
        std::cin >> r;
        std::cout << "\nArea is " << area(r);
        std::cout << "\nCircumference is " << circum(r) << "\n";
    }

    return 0;
}

