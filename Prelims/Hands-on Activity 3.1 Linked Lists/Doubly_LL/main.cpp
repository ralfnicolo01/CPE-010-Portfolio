#include <iostream>
#include "double_LL.h"

int main(){


    //creating the first node
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');
    
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;
    
    std::cout<<"Traversal Testing"<<std::endl;
    dllTraverse(head);

    std::cout<<"Insert Head Testing"<<std::endl;
    dllInsertHead('X',&head);
    dllTraverse(head);

    std::cout<<"Insert End Testing"<<std::endl;
    dllInsertEnd('1',head);
    dllTraverse(head);

    std::cout<<"Insert General Testing"<<std::endl;
    //finding the node P to insert R
    DoubleList<char> *current = head;

    while(current != nullptr && current->data != 'P'){
        current = current->next;
    }
    if(current != nullptr){
        dllInsertAny('R', current);

    }
    dllTraverse(head);

    std::cout<<"Deleting Node: "<<std::endl;
    dllDeleteNode('P', &head);
    dllTraverse(head);
}