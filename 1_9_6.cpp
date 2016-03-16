#include <iostream>

int main() {
    char *name = new char[255];
    int age;

    std::cout << "Give me your name: ";
    std::cin >> name;
    std::cout << "Give me your age: ";
    std::cin >> age;
    std::cout << "Hello " << name << ", next year you will be " << age+1 << ".\n";

    delete[] name;

    return 0;
}
