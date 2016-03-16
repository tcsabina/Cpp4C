#include <iostream>
#include <string.h>

int main() {
    char s1[] = "My string";
    char s2[10];
    int  i1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int  i2[10];

    memcpy(s2, s1, 10);
    std::cout << "s2=" << s2 << "\n";
//    memcpy(i2, i1, sizeof(int)*10);
//    std::cout << "i2=" << i2[9] << "\n";
    memcpy(i2, s1, 10);
    std::cout << "i2=" << i2[1] << "\n";

    return 0;
}

