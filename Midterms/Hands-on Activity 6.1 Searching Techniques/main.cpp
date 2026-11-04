#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main(){

    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }
    for (int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int userInput;
    std::cout << "what number to search? ";
    std::cin >> userInput;
    std::cout << "Array Result LS: ";
    linearSearchArr(max_size, userInput, dataset);

    int sortedArr[8] = {5, 10, 15, 20, 25, 30, 35, 40};

    std::cout << "Array result BS: ";
    binarySearchAR(8, 25, sortedArr);
    std::cout << "Array result BS: ";
    binarySearchAR(8, 100, sortedArr);

    //create a linklist: R A L F
    Node<char> *name1 = new_node('R');
    Node<char> *name2 = new_node('A');
    Node<char> *name3 = new_node('L');
    Node<char> *name4 = new_node('F');
    
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = nullptr;

    std::cout << "linked list result LS: ";
    linearSearchLL(name1, 'A');
    std::cout << "linked list result LS: ";
    linearSearchLL(name1, 'a');

    Node<int> *sorted1 = new_node(10);
    Node<int> *sorted2 = new_node(20);
    Node<int> *sorted3 = new_node(30);
    Node<int> *sorted4 = new_node(40);

    sorted1->next = sorted2;
    sorted2->next = sorted3;
    sorted3->next = sorted4;
    sorted4->next = nullptr;

    std::cout << "linked list result BS: ";
    binarySearchLL(sorted1, 30);
    std::cout << "linked list result BS: ";
    binarySearchLL(sorted1, 50);

  

}