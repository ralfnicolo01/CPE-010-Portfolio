#ifndef QUEUELL_H
#define QUEUELL_H

//create a class of the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

//creates the new node 
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
void enqueue(T newData,qNode<T>** frontPtr, qNode<T>** backPtr){
    //create the new node
    qNode<T>* newNode = new_node(newData);

    //inserting an item into an empty queue
    if((*frontPtr == nullptr) && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    //inserting an item into a non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue( qNode<T>** frontPtr, qNode<T>** backPtr){
    //create a temporary nodes
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);


    //check if the queue has only 1 node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    //delete the node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;
}

//check the front
template <typename T>
void checkFront(qNode<T>* frontPtr) {
    if (frontPtr == nullptr) {
        // Queue is empty
        std::cout<<"the queue is empty"<<std::endl;
        return;
    }
    else{
        std::cout<<"Front is: "<< frontPtr->data <<std::endl;
    }
}

//check the back
template <typename T>
void checkBack(qNode<T>* backPtr) {
    if (backPtr== nullptr) {
        // Queue is empty
        std::cout<<"the queue is empty"<<std::endl;
        return;
    }
    else{
        std::cout<<"Back is: "<< backPtr->data <<std::endl;
    }
}
//display all
template <typename T>
void display(qNode<T>* frontPtr) {
    // Check if the queue is empty
    if (frontPtr == nullptr) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    // Traverse and print each node
    qNode<T>* current = frontPtr;
    std::cout << "Display All: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif