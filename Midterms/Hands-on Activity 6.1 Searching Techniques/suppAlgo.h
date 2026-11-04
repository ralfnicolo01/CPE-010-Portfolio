#include "node.h"
#ifndef SUPPLEMENTARYALGO_H
#define SUPPLEMENTARYALGO_H

// problem 1
template <typename T>
int linearSearchArrCount(int arrSize, T dataFind, T list[]){
    int comparisons = 0;
    for(int i = 0; i < arrSize; i++){
        comparisons++;
        if(dataFind == list[i]){
            std::cout << "Searching is succesful\n";
            return comparisons;
        }
    }
    std::cout << "Searching is not succesful" << std::endl;
    return comparisons;
}

template <typename T>
int linearSearchLLCount(Node<T>* head, T dataFind){
    int comparisons = 0;
    while(head != nullptr){
        comparisons++;
        if(dataFind == head->data){
            std::cout << "Searching is succesful\n";
            return comparisons;
        }
        head = head->next;
    }
    std::cout << "Searching is not succesful\n";
    return comparisons;
}

// problem 2
template <typename T>
int countOccurrencesArr(int arrSize, T dataFind, T list[]){
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if(dataFind == list[i]){
            count++;
        }
    }
    return count;
}

template <typename T>
int countOccurrencesLL(Node<T>* head, T dataFind){
    int count = 0;
    while(head != nullptr){
        if(dataFind == head->data){
            count++;
        }
        head = head->next;
    }
    return count;
}

// problem 3
template <typename T>
void binarySearchAR(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize - 1, middle;

    while (low <= up){
        middle = (int)((low+up)/2);
        if (dataFind == list[middle]){
            std::cout << "the search element is found! \n";
            return;
        }
        else if (dataFind < list[middle]){
            up = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }
    std::cout << "the search element is not found! \n" << std::endl;
}

//problem 4
template <typename T>
void binarySearchARRecursive(T list[], int low, int up, T dataFind){
    if(low > up){
        std::cout << "the search element is not found! \n" << std::endl;
        return;
    }
    int middle = (int)((low+up)/2);
    if(dataFind == list[middle]){
        std::cout << "the search element is found! \n";
        return;
    }
    else if(dataFind < list[middle]){
        binarySearchARRecursive(list, low, middle-1, dataFind);
    }
    else{
        binarySearchARRecursive(list, middle+1, up, dataFind);
    }
}

#endif