#include <iostream>
#include <string.h>

class Fruit{
    private:
        std::string fruitName;
        int fruitPrice;
        int fruitQuantity;
    public:
    //constructor
    Fruit(std::string newName = "Apple", int newPrice = 0, int newQuantity = 0){
        fruitName = std::move(newName);
        fruitPrice = newPrice;
        fruitQuantity = newQuantity;
    };
    //deconstructor
    ~Fruit(){
    }
    //copy constructor
    Fruit (const Fruit &copyFruit){
        fruitName = copyFruit.fruitName;
        fruitPrice = copyFruit.fruitPrice;
        fruitQuantity = copyFruit.fruitQuantity;
    }
    //copy assignment operator
    Fruit& operator=(const Fruit &copyFruit){
        if (this == &copyFruit) return *this;
        fruitName = copyFruit.fruitName;
        fruitPrice = copyFruit.fruitPrice;
        fruitQuantity = copyFruit.fruitQuantity;
        return *this;
    }
    //Display
    void Display(){
        std::cout << "Fruit Name: " << fruitName << std::endl;
        std::cout << "Fruit Price: " << fruitPrice << std::endl;
        std::cout << "Fruit Quantity: " << fruitQuantity << std::endl;
        std::cout << "" << std::endl;
    } 
    //calculate sum
    double CalculateSum() const {
    return fruitPrice * fruitQuantity;
    }
};

class Vegetable{
    private:
        std::string vegetableName;
        int vegetablePrice;
        int vegetableQuantity;
    public:
    //constructor
    Vegetable(std::string newName = "Carrot", int newPrice = 0, int newQuantity = 0){
        vegetableName = std::move(newName);
        vegetablePrice = newPrice;
        vegetableQuantity = newQuantity;    
    };
    //deconstructor
    ~Vegetable(){
    }
    //copy constructor
    Vegetable (const Vegetable &copyVegetable){
        vegetableName = copyVegetable.vegetableName;
        vegetablePrice = copyVegetable.vegetablePrice;
        vegetableQuantity = copyVegetable.vegetableQuantity;
    }
    //copy assignment operator
    Vegetable& operator=(const Vegetable &copyVegetable){
        if (this == &copyVegetable) return *this;
        vegetableName = copyVegetable.vegetableName;
        vegetablePrice = copyVegetable.vegetablePrice;
        vegetableQuantity = copyVegetable.vegetableQuantity;
        return *this;
    }
    //Display
    void Display(){
        std::cout << "Vegetable Name: " << vegetableName << std::endl;
        std::cout << "Vegetable Price: " << vegetablePrice << std::endl;
        std::cout << "Vegetable Quantity: " << vegetableQuantity << std::endl;
        std::cout << "" << std::endl;   
    }
    //calculate sum
    double CalculateSum() const {
        return vegetablePrice * vegetableQuantity;
    }
    const char* GetName() const {
        return vegetableName.c_str();
    }
};
//total sum
double TotalSum(Fruit* list, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) total += list[i].CalculateSum();
    return total;
}
//total sum
double TotalSum(Vegetable* list, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) total += list[i].CalculateSum();
    return total;
}
//fruitlist
Fruit* fruitList =  new Fruit[2]{
    Fruit("Apple", 10, 7),
    Fruit("Banana", 10, 8),
};
//vegetablelist
Vegetable* vegetableList = new Vegetable[2]{
    Vegetable("Broccoli", 60, 12),
    Vegetable("Lettuce", 50, 10),
};  


int main(){
     //size of the list
    int vegSize = 2;
    int fruitSize = 2;

    //display the fruitlist
    for (int i = 0; i < fruitSize; i++) {
        fruitList[i].Display();
    }
    //display the vegetablelist
    for (int i = 0; i < vegSize; i++) {
        vegetableList[i].Display();
    }

    //calculate the total sum of the fruit and vegetable lists
    double grandTotal = TotalSum(fruitList, fruitSize) + TotalSum(vegetableList, vegSize);
    std::cout << "Total: PHP " << grandTotal << std::endl;
    std::cout << "" << std::endl;


    //remove the vegetable "Lettuce" from the vegetable list
    Vegetable* newVegList = new Vegetable[vegSize - 1];
    int idx = 0;
    for (int i = 0; i < vegSize; i++) {
        if (strcmp(vegetableList[i].GetName(), "Lettuce") != 0) {
            newVegList[idx++] = vegetableList[i];
        }
    }

    std::cout<< "[Removed Lettuce from the vegetable list.]" << std::endl;

    //repeat all the steps above to display the updated lists and calculate the new total sum
    delete[] vegetableList;
    vegetableList = newVegList;
    vegSize--;

    for (int i = 0; i < fruitSize; i++) {
        fruitList[i].Display();
    }

    for (int i = 0; i < vegSize; i++) {
        vegetableList[i].Display();
    }

    double grandTotal2 = TotalSum(fruitList, fruitSize) + TotalSum(vegetableList, vegSize);
    std::cout << "Total: PHP " << grandTotal2 << std::endl;

    //delete the dynamically allocated memory for the fruit and vegetable lists
    delete[] fruitList;
    delete[] vegetableList;

    return 0;
}