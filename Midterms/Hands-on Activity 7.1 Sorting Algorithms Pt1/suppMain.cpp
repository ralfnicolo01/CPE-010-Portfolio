#include <iostream>
#include <cstdlib>
#include <time.h>
#include "suppH.h"

const int maxSize = 100;
const int numCandidates = 5;

void displayArr(int arr[], int size);

int main(){
    int votesArr[maxSize];
    std::string candidates[numCandidates] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    srand(time(0));
    for(int i = 0; i < maxSize; i++){
        votesArr[i] = rand() % numCandidates + 1;
    }

    std::cout << "Unsorted Votes Array:\n";
    displayArr(votesArr, maxSize);
    std::cout << std::endl;

    insertionSort(votesArr, maxSize);

    std::cout << "Sorted Votes Array:\n";
    displayArr(votesArr, maxSize);
    std::cout << std::endl;

    countVotes(votesArr, maxSize, candidates);

    return 0;
}

//display function to display all the elements inside the array
void displayArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}