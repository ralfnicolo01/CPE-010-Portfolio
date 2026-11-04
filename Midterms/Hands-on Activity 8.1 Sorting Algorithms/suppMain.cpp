#include <iostream>
#include "suppSorting.h"

void displayArr(int arr[], int size);

int main(){

    int testArr[] = {10, 42, 15, 12, 37, 7, 9};
    int size = sizeof(testArr) / sizeof(testArr[0]);

    std::cout << "Before quickSortHybrid:\n";
    displayArr(testArr, size);

    quickSortHybrid(testArr, 0, size - 1);

    std::cout << "After quickSortHybrid:\n";
    displayArr(testArr, size);

    return 0;
}

void displayArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}