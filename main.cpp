#include <iostream>

#include "MyBudget.h"
#include "DateGenerator.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");
    myBudget.displayMainMenu();
    //myBudget.registerUser();
    //BudgetManager budgetManager("incomes.xml", "expenses.xml", 1);
    myBudget.logInUser();
    system("pause");
    myBudget.displayUserMenu();
    system("pause");
    //myBudget.addIncome();
    //system("pause");
    //myBudget.changeUserPassword();
    //myBudget.logInUser();
    //system("pause");
    //budgetManager.displayUserMenu();
    //system("pause");
    //budgetManager.addIncome();
    //budgetManager.addExpense();
    //budgetManager.showIncomes();
    //budgetManager.showExpenses();
    //budgetManager.showCashBalance();
    myBudget.showCashSummary();
    system("pause");
    myBudget.logOutUser();

    return 0;
}

