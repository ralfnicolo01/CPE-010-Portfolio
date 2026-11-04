#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

template <typename T>
class SimplyList{
    public:
     T data;
     SimplyList<T> *next = nullptr;
};


template <typename T>
void listTraversal(SimplyList<T>* head){

    if(head == nullptr){
        std::cout<<"List is empty"<<std::endl;
        return;
    }

    while(head != nullptr){
        std::cout<<head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
    std::cout<<std::endl;
}

//Head Insertion
template <typename T>
void sllinsertHead(T newData, SimplyList<T>** currentHead){
    SimplyList<T>* newNode = new SimplyList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead =  newNode;
}

//General Insertion
template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){
    if (prevNode == nullptr){
        std::cout<<"Previous Node cannot be Null"<<std::endl;
        return;
    }
    SimplyList<T>* newNode = new SimplyList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

//End Insertion
template <typename T>
void sllInsertEnd(T newData, SimplyList<T>** head){
    SimplyList<T>* newNode = new SimplyList<T>;
    SimplyList<T>* currentNode = *head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    newNode->data = newData;
    newNode->next = nullptr;
    currentNode->next = newNode;
}

//Delete Insertion
template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    if(*head == nullptr) return;
    
    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    //data was not found
    if (currNode == nullptr) return;

    //what if the node to be delted is the head node
    if (prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    //we have to delete the node
    delete currNode;
}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif