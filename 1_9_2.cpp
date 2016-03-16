#include <iostream>

int main() {
    const float y_to_m = 1.0936;
    int         yard;

    while (true) {
        std::cout << "Distance in yard: ";
        std::cin >> yard;
        if (yard <= 0)
            break;

        std::cout << "Is " << yard * y_to_m << " meter.\n";
    }

    return 0;
}
