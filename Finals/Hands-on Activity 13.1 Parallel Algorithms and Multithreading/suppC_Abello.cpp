#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void merge(std::vector<int>& a, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = 0; k < tmp.size(); k++) a[l + k] = tmp[k];
}

void mergeSort(std::vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n = 5000000;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = (i * 7919LL) % 1000003;
    std::vector<int> b = a;
    int mid = (n - 1) / 2;

    // Normal merge sort (one thread)
    auto start1 = std::chrono::steady_clock::now();
    mergeSort(a, 0, n - 1);
    auto end1 = std::chrono::steady_clock::now();

    // Multithreaded: two threads sort each half, then merge
    auto start2 = std::chrono::steady_clock::now();
    std::thread t1([&b, mid] { mergeSort(b, 0, mid); });
    std::thread t2([&b, mid, n] { mergeSort(b, mid + 1, n - 1); });
    t1.join();
    t2.join();
    merge(b, 0, mid, n - 1);
    auto end2 = std::chrono::steady_clock::now();

    std::cout << "Single thread: "
              << std::chrono::duration<double, std::milli>(end1 - start1).count() << " ms" << std::endl;
    std::cout << "Two threads:   "
              << std::chrono::duration<double, std::milli>(end2 - start2).count() << " ms" << std::endl;
    std::cout << "Same result: " << (a == b) << std::endl;
    return 0;
}