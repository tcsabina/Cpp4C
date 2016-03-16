#include <iostream>

void swap(int &i, int &j) {
    int temp;

    temp = i;
    i    = j;
    j    = temp;
}

int main() {
    int a, b;

    a = 1;
    b = 2;
    std::cout << "Before swap: a = " << a << "; b = " << b << "\n";
    swap(a, b);    
    std::cout << "After swap: a = " << a << "; b = " << b << "\n";

    return 0;
}
