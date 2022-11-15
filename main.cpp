#include <iostream>

#include "MyBudget.h"
#include "DateGenerator.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");
    myBudget.displayMainMenu();
    //myBudget.registerUser();
    BudgetManager budgetManager("incomes.xml", 1);
    //myBudget.logInUser();
    //myBudget.changeUserPassword();
    //myBudget.logInUser();
    system("pause");
    budgetManager.displayUserMenu();
    system("pause");
    budgetManager.addIncome();
    myBudget.logOutUser();
    //myBudget.logInUser();
    //myBudget.addIncome();

    return 0;
}

