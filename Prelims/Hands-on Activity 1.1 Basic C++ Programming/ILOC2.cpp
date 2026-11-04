#include <iostream>

float Convertion(float kelvin);

int main(){
float kelvin;

std::cout<<"Enter Temperature in Kelvin: ";
std::cin>> kelvin;
std::cout << "Temperature in Fahrenheit: " << Convertion(kelvin) << " F" << std::endl;

}

float Convertion(float kelvin){
    float Farehenheit = ((kelvin - 273.15) * 9/5) + 32;
    return Farehenheit;   
}
