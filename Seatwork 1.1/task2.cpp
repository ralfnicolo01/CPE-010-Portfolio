#include <iostream>
#include <string>
using namespace std;

int main() {
    string item1 = "Pepperoni Supreme";
    string item2 = "Hawaiian Delight";
    string item3 = "Margherita Classic";

    double price1, price2, price3;
    double total, payment, change;

    cout << "======================================" << endl;
    cout << "           RALF PIZZA PALACE          " << endl;
    cout << "======================================" << endl;
    cout << "1. " << item1 << endl;
    cout << "2. " << item2 << endl;
    cout << "3. " << item3 << endl;
    cout << "--------------------------------------" << endl;

    cout << "Enter price of " << item1 << ": ";
    cin >> price1;
    cout << "Enter price of " << item2 << ": ";
    cin >> price2;
    cout << "Enter price of " << item3 << ": ";
    cin >> price3;

    total = price1 + price2 + price3;
    cout << "\nTotal bill: PHP " << total << endl;

    cout << "Enter payment amount: PHP ";
    cin >> payment;

    change = payment - total;

    cout << "\n========= ORDER RECEIPT =========" << endl;
    cout << item1 << ": PHP " << price1 << endl;
    cout << item2 << ": PHP " << price2 << endl;
    cout << item3 << ": PHP " << price3 << endl;
    cout << "----------------------------------" << endl;
    cout << "Total   : PHP " << total << endl;
    cout << "Payment : PHP " << payment << endl;

    if (change < 0) {
        cout << "Amount short: PHP " << -change << endl;
        cout << "\nPayment is not enough for this order!" << endl;
    } else {
        cout << "Change  : PHP " << change << endl;
        cout << "\nThank you for ordering at Pizza Palace! Enjoy your meal!" << endl;
    }
    cout << "==================================" << endl;

    return 0;
}