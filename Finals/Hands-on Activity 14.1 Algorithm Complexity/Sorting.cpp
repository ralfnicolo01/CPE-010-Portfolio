#include <iostream>
#include <chrono>

int arr[10000];
int temp[10000];

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (k = l; k <= r; k++) a[k] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

void fillBest(int n)  { for (int i = 0; i < n; i++) arr[i] = i; }     
void fillWorst(int n) { for (int i = 0; i < n; i++) arr[i] = n - i; }  

int main() {
    int sizes[] = {100, 1000, 10000};

    for (int n : sizes) {
        auto start = std::chrono::high_resolution_clock::now();
        auto end = start;

        fillBest(n);
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        end = std::chrono::high_resolution_clock::now();
        double bubbleBest = std::chrono::duration<double, std::milli>(end - start).count();

        fillWorst(n);
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n);
        end = std::chrono::high_resolution_clock::now();
        double bubbleWorst = std::chrono::duration<double, std::milli>(end - start).count();

        fillBest(n);
        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        double mergeBest = std::chrono::duration<double, std::milli>(end - start).count();

        fillWorst(n);
        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        double mergeWorst = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "Table 14-2 (n = " << n << ")\n";
        std::cout << "\t\tBubble Sort\tMerge Sort\n";
        std::cout << "Best Case\t" << bubbleBest << " ms\t" << mergeBest << " ms\n";
        std::cout << "Worst Case\t" << bubbleWorst << " ms\t" << mergeWorst << " ms\n\n";
    }
    return 0;
}