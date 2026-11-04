#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class DoubleList {
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};
//create a new node
template <typename T>
DoubleList<T>* createNode(T newData) {
    //dynamiccaly allocante memory for a new node
    DoubleList<T>* newNode = new DoubleList<T>();

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    //return the address of the new node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode){

    DoubleList<T> *tail;
    //check if the list is empty
    if (currentNode == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    //forward traversal
    std::cout << "Forward : " << std::endl;
    //moves towards the last node 
    while(currentNode != nullptr){
        //print the data
        std::cout << currentNode->data<< " ";
        //saved the current node as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }

    std::cout << std::endl;

    //backward traversing
    std::cout << "Backward : " << std::endl;
    //move towards the head
    while(tail != nullptr){
        //printed the data
        std::cout << tail->data << " ";
        //move towards the previous node
        tail = tail->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //create a node
    DoubleList<T>* newNode = createNode(newData);
    //new node should point to the current head
    newNode->next = *currentHead;
    //current head should point back to the new
    (*currentHead)->prev = newNode;
    //update the head pointer
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    //create a node
    DoubleList<T>* newNode = createNode(newData);
    //traverse to the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    //connect the last node to the new node
    currentHead->next = newNode;
    //connect the new node back to the last node
    newNode->prev = currentHead;
}

template <typename T>
void dllInsertAny(T newData, DoubleList<T>* prevNode){
    //Check if it is the head node (previous node is null)
    if (prevNode == nullptr) {
        std::cout << "Previous Node cannot be null" << std::endl;
        return;
    }
    //Allocate a new node
    DoubleList<T>* newNode = createNode(newData);
    //Store data in the new node
    newNode->data = newData;
    //Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    //
    if(newNode->next != nullptr){
        newNode->next->prev = newNode;
    }
    //Point previous node to the new node
    prevNode->next = newNode;
}

template <typename T>
void dllDeleteNode(T key, DoubleList<T>** currentHead){
    //check if the list is empty
    if (*currentHead == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    DoubleList<T> *temp = *currentHead;

    //search for the node containing the element
    while(temp != nullptr && temp->data != key){
        temp = temp->next;
    }

    //element not found
    if(temp == nullptr){
        std::cout << "Element not found" << std::endl;
        return;
    }

    //if the node to delete is the head
    if(temp->prev == nullptr){
        *currentHead = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }

    //free the memory
    delete temp;
}

#endif