#ifndef LIST_STACK_H
#define LIST_STACK_H


//class node with dat and next members
template <typename T>
class Node {
    public:
    T data;
    Node<T>*next = nullptr;
};

//create a pointer/reference tip that always point to the current top node 
template <typename T>
Node<T>* head = nullptr;


//pushing operation:
template <typename T>
void push(T newData){
    //create a new node
    Node<T>* newNode = new Node<T>;
    //assign the data to the newnode
    newNode->data = newData;
    //point the newNodeto the current top
    newNode->next = head<T>;
    //assign the new Top the new Node
    head<T> = newNode;
}
//isEmpty() Operation:
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    //if the stack is empty error catch:
    if(isEmpty<T>()){
        std::cout<<"Stack underflow"<<std::endl;
    }
    //saving a current top node to a temporary variable
    Node<T>* temp = head<T>;
    //store the data to a temp variable 
    T tempval = temp->data;
    //move the head to next node
    head<T> = head<T>->next;
    //free up the memory
    delete temp;
    //return the temporary variable data
    return tempval;
}

template <typename T>
void Top(){
    //what if the stack is empty
    if(isEmpty<T>()) return;

    std::cout<<"the top is: "<< head<T>->data<<std::endl;  
}

template <typename T>
void displayAll(){
    std::cout<<"\nDisplay All: "<<std::endl;

    while(head<T> != nullptr){
        std::cout<<head<T>->data << " ";
        head<T> = head<T>->next;
        }
    std::cout<<"\n"<<std::endl; 
    }
#endif