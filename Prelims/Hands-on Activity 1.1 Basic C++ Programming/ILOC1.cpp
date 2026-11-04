#include <iostream>

void swap(int fNum, int sNum);

int main(){

swap (6,7);

}
void swap(int fNum, int sNum){

    int temp = fNum;
    int nfnum = sNum;
    int nsnum = temp;

    std::cout<<"fNum: "<< nfnum << std::endl;
    std::cout<<"sNum: "<< nsnum << std::endl;
}
