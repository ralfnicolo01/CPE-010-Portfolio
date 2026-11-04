#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
    //constructor
    Student(std::string newName  = "John Doe", int newAge = 18){
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout<<"Constructor was called"<<std::endl;
    };
    //deconstructor
    ~Student(){
        std::cout<<"Deconstructor was called"<<std::endl;
    }
    //copy constructor
    Student (const Student &copyStudent){
        std::cout<<"Copy Constructor called"<<std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }
    //display attributes
    void printDetails(){
        std::cout<<this->studentName<<" "<<this->studentAge<<std::endl;

    }
};

int main(){
    const size_t j = 5;

    Student studentList[j]= {};
    std::string nameList[j] = {"Carly","Freddy","Sam","Zack","Code"};
    int ageList[j] = {15, 16, 18, 19, 16};

    for(int i = 0; i < j; i++){ //loop A
        Student* ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for (int i = 0; i < j; i++){ //loop B
        studentList[i] .printDetails();
    }

    return 0;
}