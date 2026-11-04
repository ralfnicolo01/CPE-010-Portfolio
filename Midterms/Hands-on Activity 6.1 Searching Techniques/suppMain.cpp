#include <iostream>
#include "node.h"
#include "suppAlgo.h"

int main(){

    int list1[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    Node<int> *n1 = new_node(15);
    Node<int> *n2 = new_node(18);
    Node<int> *n3 = new_node(2);
    Node<int> *n4 = new_node(19);
    Node<int> *n5 = new_node(18);
    Node<int> *n6 = new_node(0);
    Node<int> *n7 = new_node(8);
    Node<int> *n8 = new_node(14);
    Node<int> *n9 = new_node(19);
    Node<int> *n10 = new_node(14);
    n1->next = n2;
    n2->next = n3; 
    n3->next = n4; 
    n4->next = n5;
    n5->next = n6; 
    n6->next = n7; 
    n7->next = n8; 
    n8->next = n9;
    n9->next = n10; 
    n10->next = nullptr;

    std::cout << "Problem 1\n";
    std::cout << "Array Result LS: ";
    int arrComparisons = linearSearchArrCount(10, 18, list1);
    std::cout << "Comparisons (array): " << arrComparisons << std::endl;

    std::cout << "Linked List Result LS: ";
    int llComparisons = linearSearchLLCount(n1, 18);
    std::cout << "Comparisons (linked list): " << llComparisons << std::endl;

    std::cout << "\nProblem 2\n";
    int arrCount = countOccurrencesArr(10, 18, list1);
    std::cout << "Occurrences of 18 (array): " << arrCount << std::endl;
    int llCount = countOccurrencesLL(n1, 18);
    std::cout << "Occurrences of 18 (linked list): " << llCount << std::endl;

    std::cout << "\nProblem 3\n";
    int list2[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    std::cout << "Array result BS: ";
    binarySearchAR(10, 8, list2);

    std::cout << "\nProblem 4\n";
    std::cout << "Array result recursive BS: ";
    binarySearchARRecursive(list2, 0, 9, 8);

}