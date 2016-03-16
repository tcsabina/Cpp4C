#include <iostream>

void print_vect(int* v, int size) {
    std::cout << "myVector = {";
    for (int i = 0; i < size; i++) {
        std::cout << v[i] << ",";
    } 
    std::cout << "}\n";
}

void create_vect(int* &v, int& size) {
    int value;

    v = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Element #" << i+1 << ": ";
        std::cin >> value;
        v[i] = value;
    }

    print_vect(v, size);

//    delete []v;
}

void add_vect(int* &v1, int* v2, int* sum, int size) {
    for (int i = 0; i < size; i++) {
        sum[i] = v1[i] + v2[i];
//        std::cout << "v1[" << i << "] = " << v1[i] << "\n";
    }
}

int main() {
    int  size1, size2, size;
    int* myVector1;
    int* myVector2;
    int* myVectorSum;

    std::cout << "Give me size1: ";
    std::cin >> size1;
    create_vect(myVector1, size1);
    std::cout << "Give me size2: ";
    std::cin >> size2;
    create_vect(myVector2, size2);
    if (size1 > size2)
        size = size2;
    else
        size = size1;

    myVectorSum = new int[size];

    add_vect(myVector1, myVector2, myVectorSum, size);
    print_vect(myVectorSum, size);

    delete []myVectorSum;
    delete []myVector1;
    delete []myVector2;

    return 0;
}

