#include <iostream>

const int ARR_SIZE = 15;

void swap(float &a, float &b) {
    float temp = a;
    a = b;
    b = temp;
}

void heapify(float arr[], int n, int i) {
    int lowest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[lowest]) {
        lowest = l;
    }
    if (r < n && arr[r] < arr[lowest]) {
        lowest = r;
    }
    if (lowest != i) {
        swap(arr[i], arr[lowest]);
        heapify(arr, n, lowest);
    }
}

void heapSort(float arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    float floats[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        std::cin >> floats[i];
    }
    heapSort(floats, ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << floats[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
