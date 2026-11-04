#include <iostream>
#include <thread>

int globalVar = 0;

void add(int value) {
    globalVar += value;
}

int main() {
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    std::cout << "Display (before any join): " << globalVar << std::endl;
    t1.join();
    std::cout << "After T1.join():           " << globalVar << std::endl;
    t2.join();
    std::cout << "After T2.join():           " << globalVar << std::endl;
    t3.join();
    std::cout << "After T3.join():           " << globalVar << std::endl;
    return 0;
}