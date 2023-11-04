#include <iostream>

const int ARR_SIZE = 15;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int arr[], int n, int i) {
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

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int numbers[ARR_SIZE] = {114, 111, 106, 107, 108, 105, 115, 108,
                             110, 109, 112, 113, 116, 117, 118};

    heapSort(numbers, ARR_SIZE);
    std::cout << "X - " << numbers[ARR_SIZE - 1] << std::endl;

    int repeating_number;
    for (int i = 0; i < ARR_SIZE - 1; i++) {
        if (numbers[i] == numbers[i + 1]) {
            repeating_number = numbers[i];
            break;
        }
    }
    std::cout << "Repeating number - " << repeating_number << std::endl;
}
