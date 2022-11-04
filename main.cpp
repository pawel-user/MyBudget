#include <iostream>

#include "MyBudget.h"

using namespace std;

int main()
{
    MyBudget myBudget("users.xml", "income.xml", "expense.xml");
    myBudget.displayMainMenu();
    myBudget.registerUser();
    myBudget.logInUser();

    return 0;
}
