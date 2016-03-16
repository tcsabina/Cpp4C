#include <iostream>

int main() {
    int i = 5;
    int* pi = &i;
    char c = 'C';
    char* pc = &c;
    void* pv;
    char s[100] = "abcdefghijklmnopqrstvwxyz";

    *pi = i + c;
    std::cout << "i = " << i << "\n";
    *pc = *(s + 10);
    std::cout << "c = " << c << "\n";
    pv = pi;
    std::cout << "*pv = " << *(int *)pv << "\n"; 
    pv = s + 1;
    std::cout << "adress of s=" << &s << "; value of *s=" << *s;
    std::cout << "; address of pv=" << &pv << "; value of pv=" << pv << "; *pv = " << *(char *)pv << "\n";
//    pv = ++s; // error

//    pc = pv; // error
//    *pc = *pv; // error
//    *pc = (char)*pv; //error
    pc = (char *)pv;
    std::cout << "adress of pc=" << &pc << "; value of *pc=" << *pc << "; value of pc=" << pc << "\n";

    return 0;
}
