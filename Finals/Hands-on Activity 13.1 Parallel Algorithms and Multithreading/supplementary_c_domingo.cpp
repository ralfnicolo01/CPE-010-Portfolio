#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>

void partial_sum(const std::vector<long long>& data, size_t start, size_t end, long long& result) {
    long long local_sum = 0;
    for (size_t i = start; i < end; ++i) {
        local_sum += data[i];
    }
    result = local_sum;
}

int main() {

    const size_t ARRAY_SIZE = 100'000'000;
    std::vector<long long> numbers(ARRAY_SIZE, 1);

    auto start_seq = std::chrono::high_resolution_clock::now();
    long long seq_sum = 0;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        seq_sum += numbers[i];
    }
    auto end_seq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> seq_duration = end_seq - start_seq;

    std::cout << "Sequential Sum Result: " << seq_sum << std::endl;
    std::cout << "Sequential Time: " << seq_duration.count() << " ms\n" << std::endl;

    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 4; // Default fallback

    std::vector<std::thread> threads;
    std::vector<long long> partial_results(num_threads, 0);
    size_t chunk_size = ARRAY_SIZE / num_threads;

    auto start_par = std::chrono::high_resolution_clock::now();

    for (unsigned int i = 0; i < num_threads; ++i) {
        size_t start_idx = i * chunk_size;
        size_t end_idx = (i == num_threads - 1) ? ARRAY_SIZE : start_idx + chunk_size;
        threads.push_back(std::thread(partial_sum, std::cref(numbers), start_idx, end_idx, std::ref(partial_results[i])));
    }
    for (auto& th : threads) {
        th.join();
    }
    long long parallel_sum = 0;
    for (long long res : partial_results) {
        parallel_sum += res;
    }

    auto end_par = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> par_duration = end_par - start_par;

    std::cout << "Parallel Sum Result (" << num_threads << " threads): " << parallel_sum << std::endl;
    std::cout << "Parallel Time: " << par_duration.count() << " ms\n" << std::endl;
    std::cout << "Speedup Factor: " << seq_duration.count() / par_duration.count() << "x" << std::endl;

    return 0;
}