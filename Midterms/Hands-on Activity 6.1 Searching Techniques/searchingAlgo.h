#include "node.h"
#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]){

    // int i = 0;

    // while(i < arrSize){
    //     if(dataFind == list[i]){
    //         std::cout << "Searching is succesful\n";
    //         return;
    //     }
    //     i++;
    // }

    for(int i = 0; i < arrSize; i++){
        if(dataFind == list[i]){
            std::cout << "Searching is succesful\n";
            return;
        }
    }

    std::cout<<"Searching is not succesful"<<std::endl;
}

template <typename T>
void linearSearchLL(Node<T>* head, T dataFind){
    
    while(head != nullptr){
        if(dataFind == head->data){
            std::cout << "Searching is succesful\n";
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is not succesful\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        //move slow one step
        slow = slow->next;

        //move fast two steps
        fast = fast->next->next;
    }
    
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){

    Node<T>* last = nullptr;

    while(start != last){

        Node<T>* mid = getMiddle(start, last);

        if(mid->data == dataFind){
            std::cout << "the data was Found" << std::endl;
            return;
        }

        if(mid->data > dataFind){
            last = mid;
        }
        else{
            start = mid->next;
        }
    }

    std::cout << "Searching is not succesful" << std::endl;
}

template <typename T>
void binarySearchAR(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize - 1, middle;
    
    while (low <= up){

        middle = (int)((low+up)/2);
        if (dataFind == list[middle]){
            std::cout << "the search element is found!\n";
            return;
        }
        else if (dataFind < list[middle]){
            up = middle - 1;
        }
        else{
            low = middle + 1;
        }
    }

    std::cout << "the search element is not found!\n";

}

#endif