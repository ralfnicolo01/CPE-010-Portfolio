#include <iostream>
#include "queueLL.h"
int main(){
    qNode<char> *front = nullptr;
    qNode<char> *back = nullptr;

    enqueue('R', &front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;
    enqueue('A', &front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;
    enqueue('L', &front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;
    enqueue('F', &front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;

    display(front);
    checkFront(front);
    checkBack(back);

    dequeue(&front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<< front->data <<" "<< back->data<<std::endl;

    return 0;
}