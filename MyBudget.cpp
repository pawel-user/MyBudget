#include "MyBudget.h"

void MyBudget::displayMainMenu() {
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. LogIn" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
}

void MyBudget::registerUser() {
    userManager.registerUser();
}

void MyBudget::logInUser() {
    userManager.logInUser();
}

