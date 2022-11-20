#include <iostream>

#include "MyBudget.h"

using namespace std;

int main() {
    MyBudget myBudget("users.xml", "incomes.xml", "expenses.xml");

    while (true) {
        if (!myBudget.ifUserLoggedIn()) {
            myBudget.displayMainMenu();

            switch (myBudget.chooseOptionFromMainMenu()) {
            case '1':
                myBudget.registerUser();
                break;
            case '2':
                myBudget.logInUser();
                break;
            case '9':
                system("cls");
                exit(0);
                break;
            default:
                myBudget.displayMessageNoOption();
                break;
            }
        } else {
            myBudget.displayUserMenu();

            switch (myBudget.chooseOptionFromUserMenu()) {
            case '1':
                if (myBudget.ifUserLoggedIn()) {
                    myBudget.addIncome();
                } else {
                    cout << "In order to add a recipient, you must first log in." << endl;
                    system("pause");
                }
                break;
            case '2':
                myBudget.addExpense();
                break;
            case '3':
                myBudget.showCashSummaryForCurrentMonth();
                break;
            case '4':
                myBudget.showCashSummaryForPreviousMonth();
                break;
            case '5':
                myBudget.showCashSummaryForSelectedPeriod();
                break;
            case '8':
                myBudget.changeUserPassword();
                break;
            case '9':
                myBudget.logOutUser();
                break;
            default:
                myBudget.displayMessageNoOption();
                break;
            }
        }
    }
    return 0;
}
