#include <iostream>
#include <chrono>

int arr[100000];

int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) return i;
    }
    return -1;
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int sizes[] = {1000, 10000, 100000};
    int repeat = 1000; 
    int key = -1;        
    int result = 0;

    std::cout << "N\tBinary Search (ms)\tLinear Search (ms)\n";

    for (int n : sizes) {
        for (int i = 0; i < n; i++) arr[i] = i;

        auto start = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) result += binarySearch(arr, n, key);
        auto end = std::chrono::high_resolution_clock::now();
        double binaryTime = std::chrono::duration<double, std::milli>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) result += linearSearch(arr, n, key);
        end = std::chrono::high_resolution_clock::now();
        double linearTime = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << n << "\t" << binaryTime << "\t\t\t" << linearTime << "\n";
    }

    std::cout << "(checksum: " << result << ")\n";
    return 0;
}