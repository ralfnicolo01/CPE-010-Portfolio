#include <iostream>
#include <cmath>

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
        double sideA, sideB, sideC;
    public:
        Triangle(double A, double B, double C, double sA, double sB, double sC);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();

        double computeArea();
        double computePerimeter();
        std::string classifyTriangle();
};

int main(){

    Triangle set1(60, 60, 60, 5, 5, 5);

    if(set1.validateTriangle()){
        std::cout << "The shape is a valid triangle \n";
    } else {
        std::cout << "The shape is NOT valid triangle \n";
    }

    std::cout << "Perimeter: " << set1.computePerimeter() << "\n";
    std::cout << "Area: " << set1.computeArea() << "\n";
    std::cout << "Classification: " << set1.classifyTriangle() << "\n";

}

Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle(){
    return(totalAngle <= 180);
}

// a. Area (Heron's formula)
double Triangle::computeArea(){
    double s = (sideA + sideB + sideC) / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

// b. Perimeter
double Triangle::computePerimeter(){
    return sideA + sideB + sideC;
}

// c. Classify triangle
std::string Triangle::classifyTriangle(){
    if(angleA < 90 && angleB < 90 && angleC < 90){
        return "Acute-angled";
    } else if(angleA > 90 || angleB > 90 || angleC > 90){
        return "Obtuse-angled";
    } else {
        return "Others";
    }
}