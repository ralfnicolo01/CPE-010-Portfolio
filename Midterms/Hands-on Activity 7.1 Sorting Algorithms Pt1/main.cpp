#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"


const int maxSize = 100;

void displayArr(int arr[]);

int main(){
    
    //create an array containing 100 randomly generated values
    int unsortedArr[maxSize];
    srand(time(0));
    for(int i= 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);
    std::cout << std::endl;

    std::cout << "Insertion Sort:\n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    return 0;
}

//display function to display all the elements inside the function
void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout<< arr[i] <<" ";
    }
    std::cout << std::endl;
}