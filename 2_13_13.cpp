#include <iostream>

void minmax(int data[], int size, int* min, int* max) {
    *min = *max = data[0];
    for (int i = 1; i < size; ++i) {
        if (*min > data[i])
            *min = data[i];
        else if (*max < data[i])
            *max = data[i];
    }
}

void minmax2(int* data, int size, int& min, int& max) {
    min = max = data[0];
    for (int i = 1; i < size; ++i) {
        if (min > data[i])
            min = data[i];
        else if (max < data[i])
            max = data[i];
    }
}
int main() {
    int a[] = {1, 4, 2, 6, 3};
    int min, max;

    minmax(a, 5, &min, &max);
    std::cout << "min = " << min << "; max = " << max << "\n";
    minmax2(a, 5, min, max);
    std::cout << "min = " << min << "; max = " << max << "\n";

    return 0;
}

