#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // shift larger items to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (i) std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << '\n';
}

int main() {
    int arr[] = {5, 23, 17, 8, 3};
    int n = static_cast<int>(sizeof(arr) / sizeof(arr[0]));
    std::cout << "Before: "; printArray(arr, n);
    insertionSort(arr, n);
    std::cout << "After:  "; printArray(arr, n);
    return 0;
}
