#ifndef MYBUDGET_H
#define MYBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class MyBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILENAME;
    const string EXPENSE_FILENAME;
public:
    MyBudget(string userFilename, string incomeFilename, string expenseFilename)
    : userManager(userFilename), INCOME_FILENAME(incomeFilename), EXPENSE_FILENAME(expenseFilename) {
        budgetManager = NULL;
    };
    ~MyBudget() {
        delete budgetManager;
        budgetManager = NULL;
    };

    void displayMainMenu();
//private:
    void registerUser();
    void logInUser();
    void logOutUser();
    void changeUserPassword();

    void displayUserMenu();
    void addIncome();
    void addExpense();
};

#endif // MYBUDGET_H
