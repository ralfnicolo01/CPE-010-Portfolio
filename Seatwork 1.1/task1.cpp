#include <iostream>
using namespace std;

int main() {

    int quiz1, quiz2, quiz3;
    float avg;
    float total;

    cout << "enter score for quiz 1: ";
    cin >> quiz1;
    cout << "enter score for quiz 2: ";
    cin >> quiz2;
    cout << "enter score for quiz 3: ";
    cin >> quiz3;

    avg = (quiz1 + quiz2 + quiz3)/3;
    cout << "Average is: ";
    cout << avg;
    cout << endl;

    total = quiz1 + quiz2 + quiz3;
    cout << "Total is: ";
    cout << total;
    return 0;
}
