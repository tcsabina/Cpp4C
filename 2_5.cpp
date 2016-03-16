#include <iostream>

int i = 1;

int main() {
    int i = 2;

    {
        std::cout << "entering inner block\n";
        int n = i;
        int i = 3;
        std::cout << i << "  i <> ::i  " << ::i << "\n";
        std::cout << "n = " << n << "\n";
    }

    std::cout << "entering outer block\n";
    std::cout << i << "  i <> ::i  " << ::i << "\n";

    return  0;
}
