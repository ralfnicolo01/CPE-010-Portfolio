#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"


const int maxSize = 100;

void displayArr(int arr[]);
void copyArr(int source[], int destination[]);

int main(){
    
    int unsortedArr[maxSize];
    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);
    std::cout << std::endl;

    int shellArr[maxSize];
    copyArr(unsortedArr, shellArr);
    std::cout << "Shell Sort:\n";
    shellSort(shellArr, maxSize);
    displayArr(shellArr);
    std::cout << std::endl;

    int mergeArr[maxSize];
    copyArr(unsortedArr, mergeArr);
    std::cout << "Merge Sort:\n";
    mergeSort(mergeArr, 0, maxSize - 1);
    displayArr(mergeArr);
    std::cout << std::endl;

    int quickArr[maxSize];
    copyArr(unsortedArr, quickArr);
    std::cout << "Quick Sort:\n";
    quickSort(quickArr, 0, maxSize - 1);
    displayArr(quickArr);
    std::cout << std::endl;

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void copyArr(int source[], int destination[]){
    for(int i = 0; i < maxSize; i++){
        destination[i] = source[i];
    }
}