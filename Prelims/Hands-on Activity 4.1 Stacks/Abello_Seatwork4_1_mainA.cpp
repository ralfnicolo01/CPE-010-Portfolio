#include <iostream>
#include <stack> // call the stack from the STL

int main(){
    // created an object
    std::stack<int> newStack;
    std::stack<int> stack1;
    std::stack<int> stack2;

    //testing the empty()
    std::cout<<"Is the stack empty? " <<newStack.empty()<<std::endl;

    //insert a 3 elements:
    newStack.push(3);
    std::cout<<"Top of stack: " <<newStack.top()<<std::endl;
    newStack.push(2);
    std::cout<<"Top of stack: " <<newStack.top()<<std::endl;
    newStack.push(1);
    std::cout<<"Top of stack: " <<newStack.top()<<std::endl;

    std::cout<<"Is the stack empty? " <<newStack.empty()<<std::endl;
    newStack.push(6);
    newStack.push(7);
    newStack.push(8);
    std::cout<<"Size of the stack is " <<newStack.size()<<std::endl;

    //swap
    stack1.push(1);
    stack2.push(2);
    stack1.swap(stack2);
    std::cout<<"Swapping: "<<std::endl;
    std::cout<<"Top of stack 1: " <<stack1.top()<<std::endl;
    std::cout<<"Top of stack 2: " <<stack2.top()<<std::endl;

}