#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "AuxilaryMethods.h"
#include "DateGenerator.h"
#include "Income.h"
#include "IncomeFile.h"
#include "Expense.h"
#include "ExpenseFile.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BudgetManager {
private:
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    Income enterNewIncome();
    Expense enterNewExpense();
    void displayIncomeData(Income income);
    void displayExpenseData(Expense expense);

public:
    BudgetManager(string incomeFilename, string expenseFilename, int loggedUserId)
        : LOGGED_USER_ID(loggedUserId), incomeFile(incomeFilename), expenseFile(expenseFilename) {
        loadUserIncomes();
        loadUserExpenses();
     };

    void displayUserMenu();
    char chooseOptionFromUserMenu();
    void sortCashOperationsByDate();

    void addIncome();
    void loadUserIncomes();
    void showIncomes(int lowerDate, int upperDate);

    void addExpense();
    void loadUserExpenses();
    void showExpenses(int lowerDate, int upperDate);

    void showCashBalance(int lowerDate, int upperDate);
};

#endif // BUDGETMANAGER_H
