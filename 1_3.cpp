#include <iostream>

int main() {
    int add3(int, int, int);
    float average(int);
    int s1, s2, s3, sum;

    std::cout << "\nEnter 3 scores: ";
    std::cin >> s1 >> s2 >> s3;
    sum = add3(s1, s2, s3);
    std::cout << "\nTheir average is " << average(sum) << ".\n";
    sum = add3(1.5 * s1, s2, s3);
    std::cout << "\nTheir weighted sum is " << sum << ".\n"; 
    std::cout << "\nTheir average is " << average(sum) << ".\n";
}

int add3(int a, int b, int c) {
    return a+b+c;
}

float average(int s) {
    return s/3;
}

