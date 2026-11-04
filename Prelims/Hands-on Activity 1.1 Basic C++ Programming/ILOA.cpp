#include <iostream>

int fNUm = 6;
int sNum = 7;

int sumOfTwoNum(int fNum, int sNum);
void greaterThan (int fNum,int sNum);
void booleanCheck (int fNum,int sNum);

int main(){

std::cout<<"sum is: "<<sumOfTwoNum(fNUm,sNum)<<"\n";
greaterThan (fNUm,sNum);
booleanCheck (true,false);

}
int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;

    return sum;
}
void greaterThan (int fNum,int sNum){
    
    if (fNum > sNum){
    std::cout<<"first number is larger ";

    }
    else{
    std::cout<<"second number is larger "<<std::endl;
    }
}
void booleanCheck (int fNum,int sNum){

    bool AND = fNum && sNum;
    bool OR = fNum || sNum;
    bool NOT = !fNum;
    bool XOR = fNum ^ sNum;

    if(fNum == true){
    std::cout<<"True or False: "<< AND << std::endl;    
    }
    else if(sNum == false){
    std::cout<<"True or False: "<< AND << std::endl;     
    }
    else {
        std::cout<<"failed"<< std::endl;
    }

     if(fNum == true){
    std::cout<<"True or False: "<< OR << std::endl;    
    }
    else if(sNum == false){
    std::cout<<"True or False: "<< OR << std::endl;     
    }
    else {
        std::cout<<"failed"<< std::endl;
    }

     if(fNum == true){
    std::cout<<"True or False: "<< NOT << std::endl;    
    }
    else if(sNum == false){
    std::cout<<"True or False: "<< NOT << std::endl;     
    }
    else {
        std::cout<<"failed"<< std::endl;
    }

    if(fNum == true){
        std::cout<<"success"<< XOR<< std::endl     
    }

    else if(sNum == false){
        std::cout<<"success"<< XOR<< std::endl  
    
}