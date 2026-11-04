#include <iostream>
#include <thread>
#include <chrono>

int global_counter = 0;

void add_value(int val) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    global_counter += val;
}

int main() {
    global_counter = 0;
    std::cout << "Initial global_counter: " << global_counter << std::endl;

    std::thread t1(add_value, 10);
    std::thread t2(add_value, 20);
    std::thread t3(add_value, 30);

    std::cout << "[Before T1.join()] Current global_counter: " << global_counter << std::endl;
    t1.join();
    std::cout << "[After T1.join()]  Current global_counter: " << global_counter << std::endl;
    std::cout << "[Before T2.join()] Current global_counter: " << global_counter << std::endl;
    t2.join();
    std::cout << "[After T2.join()]  Current global_counter: " << global_counter << std::endl;
    std::cout << "[Before T3.join()] Current global_counter: " << global_counter << std::endl;
    t3.join();
    std::cout << "[After T3.join()]  Final global_counter: " << global_counter << std::endl;

    return 0;
}