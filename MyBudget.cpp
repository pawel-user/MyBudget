#include "MyBudget.h"

void MyBudget::displayMainMenu() {
    system("cls");
    cout << "    >>> MAIN MENU <<<"         << endl;
    cout << "---------------------------"   << endl;
    cout << "1. Register"                   << endl;
    cout << "2. LogIn"                      << endl;
    cout << "9. Exit"                       << endl;
    cout << "---------------------------"   << endl << endl;
}

void MyBudget::registerUser() {
    userManager.registerUser();
}

void MyBudget::logInUser() {
    userManager.logInUser();
}

void MyBudget::changeUserPassword() {
    userManager.changeUserPassword();
}

void MyBudget::logOutUser() {
    userManager.logOutUser();
}

void MyBudget::displayUserMenu() {
    budgetManager->displayUserMenu();
}

void MyBudget::addIncome() {
    budgetManager->addIncome();
}
