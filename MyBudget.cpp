#include "MyBudget.h"

bool MyBudget::ifUserLoggedIn() {
    return userManager.ifUserLoggedIn();
}

char MyBudget::chooseOptionFromMainMenu() {
    return userManager.chooseOptionFromMainMenu();
}

void MyBudget::displayMainMenu() {
    userManager.displayMainMenu();
}

void MyBudget::registerUser() {
    userManager.registerUser();
}

void MyBudget::logInUser() {
    userManager.logInUser();
    budgetManager = new BudgetManager(INCOME_FILENAME, EXPENSE_FILENAME, userManager.getLoggedUserId());
}

void MyBudget::displayMessageNoOption() {
    cout << endl << "There is no such option in the menu." << endl << endl;
    system("pause");
}

void MyBudget::changeUserPassword() {
    userManager.changeUserPassword();
}

void MyBudget::logOutUser() {
    userManager.logOutUser();
}

char MyBudget::chooseOptionFromUserMenu() {
    return budgetManager->chooseOptionFromUserMenu();
}

void MyBudget::displayUserMenu() {
    budgetManager->displayUserMenu();
}

void MyBudget::addIncome() {
    budgetManager->addIncome();
}

void MyBudget::addExpense() {
    budgetManager->addExpense();
}

void MyBudget::showCashSummaryForCurrentMonth() {
    string lowerDateFormat = "", upperDateFormat = "";
    int lowerDate = 0, upperDate = 0;
    string currentYear = "", currentMonth = "";
    SYSTEMTIME st;
    GetSystemTime(&st);

    const int LAST_SINGLE_DIGIT = 9;
    const int UPPER_LIMIT_OF_DAY = DateGenerator::howManyDaysInMonth(st.wMonth, st.wYear);

    currentYear = to_string(st.wYear);

    if (st.wMonth > LAST_SINGLE_DIGIT) {
        currentMonth = to_string(st.wMonth);
    } else {
        currentMonth = "0" + to_string(st.wMonth);
    }

    lowerDateFormat = currentYear + currentMonth + "01";
    upperDateFormat = currentYear + currentMonth + to_string(UPPER_LIMIT_OF_DAY);

    lowerDate = stoi(lowerDateFormat);
    upperDate = stoi(upperDateFormat);

    budgetManager->sortCashOperationsByDate();
    budgetManager->showIncomes(lowerDate, upperDate);
    budgetManager->showExpenses(lowerDate, upperDate);

    cout << endl << "       >>> CASH SUMMARY FOR CURRENT MONTH <<<" << endl;
    cout << "---------------------------------------------------" << endl;

    budgetManager->showCashBalance(lowerDate, upperDate);
}

void MyBudget::showCashSummaryForPreviousMonth() {
    string lowerDateFormat = "", upperDateFormat = "";
    int lowerDate = 0, upperDate = 0;
    string actualYear = "", previousMonth = "";
    SYSTEMTIME st;
    GetSystemTime(&st);
    int year = st.wYear;
    int month = st.wMonth;

    const int LAST_SINGLE_DIGIT = 9;
    if (month != 1) {
        month = st.wMonth - 1;
    } else {
        year = st.wYear - 1;
        month = 12;
    }
    const int UPPER_LIMIT_OF_DAY = DateGenerator::howManyDaysInMonth(month, year);
    actualYear = to_string(year);

    if (st.wMonth > LAST_SINGLE_DIGIT) {
        previousMonth = to_string(month);
    } else {
        previousMonth = "0" + to_string(month);
    }

    lowerDateFormat = actualYear + previousMonth + "01";
    upperDateFormat = actualYear + previousMonth + to_string(UPPER_LIMIT_OF_DAY);

    lowerDate = stoi(lowerDateFormat);
    upperDate = stoi(upperDateFormat);

    budgetManager->sortCashOperationsByDate();
    budgetManager->showIncomes(lowerDate, upperDate);
    budgetManager->showExpenses(lowerDate, upperDate);

    cout << endl << ">>>        CASH SUMMARY FOR PREVIOUS MONTH <<<" << endl;
    cout << "---------------------------------------------------" << endl;

    budgetManager->showCashBalance(lowerDate, upperDate);
}

void MyBudget::showCashSummaryForSelectedPeriod() {
    string givenDate = "";
    int lowerDate = 0;
    int upperDate = 0;

    do {
        cout << endl << "Enter the lower date in format (yyyy-mm-dd) from which I should show the cash balance: ";
        do {
            givenDate = AuxilaryMethods::loadLines();
        } while (!DateGenerator::checkFormatDate(givenDate));
        lowerDate = DateGenerator::convertDateToInt(givenDate);
    } while ( !DateGenerator::checkDate(givenDate) );

    givenDate = "";

        do {
            if (upperDate < lowerDate && upperDate != 0 && lowerDate != 0) {
                cout << endl << "The date entered is less than the lower limit. \nEnter the date which is greater than " << DateGenerator::convertIntToDate(lowerDate) << ": ";
            } else {
                cout << endl << "Enter the upper date in the format (yyyy-mm-dd) by which I should show the cash balance: ";
            }
            do {
                givenDate = AuxilaryMethods::loadLines();
            } while (!DateGenerator::checkFormatDate(givenDate));
            upperDate = DateGenerator::convertDateToInt(givenDate);
        } while ( !DateGenerator::checkDate(givenDate) || (lowerDate > upperDate) );

        cout << "The date given is correct." << endl << endl;

    budgetManager->sortCashOperationsByDate();
    budgetManager->showIncomes(lowerDate, upperDate);
    budgetManager->showExpenses(lowerDate, upperDate);

    cout << endl << ">>> CASH SUMMARY FROM " << DateGenerator::convertIntToDate(lowerDate);
    cout <<" TO " << DateGenerator::convertIntToDate(upperDate) << " <<<" << endl;
    cout << "---------------------------------------------------" << endl;

    budgetManager->showCashBalance(lowerDate, upperDate);
}
