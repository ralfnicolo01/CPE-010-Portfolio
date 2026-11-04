#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// Algorithm Unique(A) from Problem 1
bool isUnique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i] == A[j]) {
                return false; // Duplicate found
            }
        }
    }
    return true; // All elements are unique
}

// Helper function to run Experimental Analysis
void runExperiment(const std::vector<int>& sizes) {
    std::cout << std::left << std::setw(12) << "Size (n)"
              << std::setw(25) << "Worst-Case Time (ms)"
              << std::setw(25) << "Best-Case Time (ms)" << "\n";
    std::cout << std::string(62, '-') << "\n";

    for (int n : sizes) {
        // Worst Case: All elements unique (must run all comparisons)
        std::vector<int> worstCaseArr(n);
        for (int i = 0; i < n; ++i) worstCaseArr[i] = i;

        auto start = std::chrono::high_resolution_clock::now();
        isUnique(worstCaseArr);
        auto end = std::chrono::high_resolution_clock::now();
        double worstTimeMs = std::chrono::duration<double, std::milli>(end - start).count();

        // Best Case: Duplicate at the very start (exits on first loop pass)
        std::vector<int> bestCaseArr(n);
        bestCaseArr[0] = 1;
        bestCaseArr[1] = 1;
        for (int i = 2; i < n; ++i) bestCaseArr[i] = i;

        start = std::chrono::high_resolution_clock::now();
        isUnique(bestCaseArr);
        end = std::chrono::high_resolution_clock::now();
        double bestTimeMs = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << std::left << std::setw(12) << n
                  << std::setw(25) << worstTimeMs
                  << std::setw(25) << bestTimeMs << "\n";
    }
}

int main() {
    std::vector<int> test1 = {1, 5, 8, 3, 9};
    std::vector<int> test2 = {1, 5, 8, 5, 9};

    std::cout << std::boolalpha;
    std::cout << "Test 1 Unique: " << isUnique(test1) << "\n"; // Output: true
    std::cout << "Test 2 Unique: " << isUnique(test2) << "\n\n"; // Output: false

    std::cout << "--- Experimental Analysis ---\n";
    runExperiment({5000, 10000, 20000, 40000});

    return 0;
}