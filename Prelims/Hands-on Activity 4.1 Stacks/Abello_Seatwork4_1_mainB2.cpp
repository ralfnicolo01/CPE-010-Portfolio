#include <iostream>
#include "listStack.h"

int main(){
    std::cout<<"------ Pushing 'I 'E' 'E' 'E' ------ \n";

    //pushing
    push('I');
    push('E');
    push('E');
    push('E');
    
    //display top
    Top<char>();

       displayAll<char>();

    //pop and print each element
     std::cout<<"------ Popping 'I 'E' 'E' 'E' ------ \n";
     while(!isEmpty<char>()){
        std::cout<<"popping: "<<pop<char>()<<std::endl;
     }

     //test stack overflow
     pop<char>();

  


    return 0;
}