#include <iostream>

int main() {
    int** data;
    int   sz1, sz2;

    std::cout << "Enter two sizes: ";
    std::cin >> sz1 >> sz2;
    data = new int*[sz1];
    for (int i = 0; i < sz1; i++) {
        data[i] = new int[sz2];
    }

    std::cout << "Enter " << sz1 << " by " << sz2 << " ints.\n";
    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            std::cin >> data[i][j];
        }
    }

    for (int i = 0; i < sz1; i++) {
        for (int j = 0; j < sz2; j++) {
            std::cout << data[i][j] << "\t";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    for (int i = 0; i < sz1; i++) {
        delete []data[i];
    }

    delete []data;

    return 0;
}

