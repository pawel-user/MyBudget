#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "AuxilaryMethods.h"
#include "DateGenerator.h"
#include "Income.h"
#include "IncomeFile.h"

#include <iostream>
#include <vector>

using namespace std;

class BudgetManager {
private:
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomeFile incomeFile;

    Income enterNewIncome();
public:
    BudgetManager(string incomeFilename, int loggedUserId)
    : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFilename) {
        loadUserIncomes();
    };

    void displayUserMenu();

    void addIncome();
    void loadUserIncomes();
};

#endif // BUDGETMANAGER_H
