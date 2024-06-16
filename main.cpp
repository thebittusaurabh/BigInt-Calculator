#include <iostream>
#include "BigInt.h"
using namespace std;

void displayMenu() {
    cout << "BigInt Calculator" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        if (choice == 3) break;

        string num1, num2;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        BigInt bigint1(num1);
        BigInt bigint2(num2);
        BigInt result;

        switch (choice) {
            case 1:
                result = bigint1 + bigint2;
                break;
            case 2:
                result = bigint1 - bigint2;
                break;
            default:
                cout << "Invalid option." << endl;
                continue;
        }
        cout << "Result: " << result << endl;
    }

    return 0;
}
