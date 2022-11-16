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

    void addIncome();
    void loadUserIncomes();
    void showIncomes();

    void addExpense();
    void loadUserExpenses();
    void showExpenses();

    void showCashBalance();
};

#endif // BUDGETMANAGER_H
