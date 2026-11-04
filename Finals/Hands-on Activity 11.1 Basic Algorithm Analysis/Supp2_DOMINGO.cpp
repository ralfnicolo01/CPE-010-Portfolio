#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

long long rpower(int x, int n) {
    if (n == 0) return 1;                  
    else return x * rpower(x, n - 1);       
}

long long brpower(int x, int n) {
    if (n == 0) return 1;                  
    if (n % 2 != 0) {                      
        long long y = brpower(x, (n - 1) / 2); 
        return x * y * y;                   
    } else {                               
        long long y = brpower(x, n / 2);   
        return y * y;                     
    }

}
void runPowerExperiment(const std::vector<int>& exponents) {
    int base = 2;
    std::cout << std::left << std::setw(15) << "Exponent (n)"
              << std::setw(25) << "rpower Time (ns)"
              << std::setw(25) << "brpower Time (ns)" << "\n";
    std::cout << std::string(65, '-') << "\n";

    for (int n : exponents) {
        // Measure rpower
        auto start = std::chrono::high_resolution_clock::now();
        volatile long long res1 = rpower(base, n);
        auto end = std::chrono::high_resolution_clock::now();
        double rpowerTime = std::chrono::duration<double, std::nano>(end - start).count();

        // Measure brpower
        start = std::chrono::high_resolution_clock::now();
        volatile long long res2 = brpower(base, n);
        end = std::chrono::high_resolution_clock::now();
        double brpowerTime = std::chrono::duration<double, std::nano>(end - start).count();

        std::cout << std::left << std::setw(15) << n
                  << std::setw(25) << rpowerTime
                  << std::setw(25) << brpowerTime << "\n";
    }
}

int main() {
    std::cout << "--- Problem 2 Verification ---\n";
    std::cout << "rpower(2, 10) = " << rpower(2, 10) << "\n";   
    std::cout << "brpower(2, 10) = " << brpower(2, 10) << "\n\n"; 

    std::cout << "--- Experimental Analysis ---\n";
    runPowerExperiment({100, 1000, 5000, 10000, 20000});

    return 0;
}