#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    //create an object
    std::queue<char> myQ;

    myQ.push('R');
    myQ.push('A');
    myQ.push('L');
    myQ.push('F');
    
    display(myQ);

    // try all member fucntions:
    //empty
    std::cout<<"Is the queue empty: "<<myQ.empty()<<std::endl;
    //size
    std::cout<<"Size of the Queue: "<<myQ.size()<<std::endl;
    //front
    std::cout << "Front element: " << myQ.front() << std::endl;
    //back
    std::cout << "Back element: " << myQ.back() << std::endl; 
    //pop
    myQ.pop();
    std::cout << "Popped an element " << std::endl; 
    //push
    myQ.push('N');
    std::cout << "Pushed an element " << std::endl;
    //display
    display(myQ);
  
    return 0;
}

void display(std::queue<char> copyQ){
    //creates a copy of the queue that was passed
    std::queue<char> c = copyQ;
    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<"\n";
}




