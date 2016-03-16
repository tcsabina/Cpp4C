#include <iostream>

void shift(char* pc1, char* pc2, char* pc3, char* pc4) {
    char temp;

    temp = *pc1;
    *pc1 = *pc2;
    *pc2 = *pc3;
    *pc3 = *pc4;
    *pc4 = temp;
}

void shift2(char& c1, char& c2, char& c3, char& c4) {
    char temp;

    temp = c1;
    c1   = c2;
    c2   = c3;
    c3   = c4;
    c4   = temp;
}

int main() {
    char s1[] = "abcd";
    char s2[] = "1234";

    std::cout << "s1 = " << s1 << "\n";
    shift(s1+0, s1+1, s1+2, s1+3);
    std::cout << "s1 = " << s1 << "\n";

    std::cout << "s2 = " << s2 << "\n";
    shift2(*(s2+0), *(s2+1), *(s2+2), *(s2+3));
    std::cout << "s2 = " << s2 << "\n";

    return 0;
}

