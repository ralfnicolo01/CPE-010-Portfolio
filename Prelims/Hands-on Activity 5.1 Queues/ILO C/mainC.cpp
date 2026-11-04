#include <iostream>
#include "queueSupp.h"

int main() {
    Printer officePrinter;

    std::cout << "--- Two users send jobs first ---\n";
    officePrinter.addJob(Job(1, "Ralf", 5));
    officePrinter.addJob(Job(2, "John", 12));

    std::cout << "\n--- Printer starts processing ---\n";
    officePrinter.processOne(); // Job 1 gets printed

    std::cout << "\n--- More users send jobs while printer is busy ---\n";
    officePrinter.addJob(Job(3, "Josh", 3));
    officePrinter.addJob(Job(4, "Dirk", 8));

    std::cout << "\n--- Printer finishes the rest, first come first served ---\n";
    officePrinter.processAll(); // Jobs 2, 3, 4 in that order

    std::cout << "\n--- Trying to process again on an empty queue ---\n";
    officePrinter.processAll();

    return 0;
}