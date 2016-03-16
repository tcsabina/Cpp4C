#include <iostream>

int main() {
    int* data;
    int  size;

    std::cout << "\nEnter array size: ";
    std::cin >> size;

    data = new int[size];
    for (int i = 0; i < size; ++i)
        std::cout << (data[i] = i) << "\t";

    std::cout << "\n\n";

    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; ++i)
//        std::cout << data[i] << "\t"; // valgrind error
        std::cout << (data[i] = i) << "\t";


    delete[] data;
    std::cout << "\n";
}
