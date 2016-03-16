#include <iostream>

const float m_to_km = 1.609;

inline int convert(int mi) { return mi * m_to_km; }

int main() {
    int miles;

    do {
        std::cout << "Input distance in miles: ";
        std::cin >> miles;
        std::cout << "\nDistance is " << convert(miles) << " km.\n";
    } while (miles > 0);

    return 0;
}

