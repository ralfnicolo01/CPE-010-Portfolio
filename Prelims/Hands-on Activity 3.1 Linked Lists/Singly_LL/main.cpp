#include <iostream>
#include "singly_LL.h"

int main(){

    //creating an empty list
    SimplyList<char> *head = new SimplyList<char>;
    SimplyList<char> *second = new SimplyList<char>;
    SimplyList<char> *third = new SimplyList<char>;
    SimplyList<char> *fourth = new SimplyList<char>;
    SimplyList<char> *fifth = nullptr;

    //assign the data:
    head->data = 'R';
    head->next = second;

    second->data = 'A';
    second->next = third;

    third->data = 'L';
    third->next = fourth;

    fourth->data = 'F';
    fourth->next = nullptr;


    std::cout<<"Accessing Each Nodes:"<<std::endl;
    std::cout<<head->next->next->data<<second->data<<std::endl;

    std::cout<<"Original List:"<<std::endl;
    listTraversal(head);

    std::cout<<"inserting a new node at the head:"<<std::endl;
    sllinsertHead('A',&head);
    listTraversal(head);

    std::cout<<"General Insetion:"<<std::endl;
    sllGeneralInsert('B',head->next->next);
    listTraversal(head);

    std::cout<<"End Insertion:"<<std::endl;
    sllInsertEnd('C', &head);
    listTraversal(head);

    std::cout<<"Delete Insertion:"<<std::endl;
    sllDeleteNode('B',&head);
    listTraversal(head);

    std::cout<<"Delete All:"<<std::endl;
    sllDeleteList(&head);
    listTraversal(head);

    return 0;
}