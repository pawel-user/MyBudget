#include "BudgetManager.h"

void BudgetManager::displayUserMenu() {
    system("cls");
    cout << "           >>> USER MENU <<<"          << endl;
    cout << "-------------------------------------" << endl;
    cout << "1. Add income"                         << endl;
    cout << "2. Add expense"                        << endl;
    cout << "3. Display current month's balance"    << endl;
    cout << "4. Display previous month's balance"   << endl;
    cout << "5. Display balance of selected period" << endl;
    cout << "-------------------------------------" << endl;
    cout << "8. Change password"                    << endl;
    cout << "9. Log out"                            << endl;
    cout << "-------------------------------------" << endl << endl;
}

void BudgetManager::addIncome() {

    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncome();

    incomes.push_back(income);

    if ( incomeFile.addIncomeToFile(income) )
        cout << endl << "New income has been added." << endl;
    else
        cout << "Error! Failed to add new income to file." << endl;
    system("pause");
}

Income BudgetManager::enterNewIncome() {
    Income income;
    string date = "", item = "";
    int incomeDate = 0;

    income.setIncomeId(incomeFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    char key = ' ';
    cout << "Does the income relate to today?" << endl;
    cout << "Type 'y' key if yes or other key if no. (y/other key)... ";

    key = tolower(AuxilaryMethods::loadCharacter());

    if (key == 'y') {
        date = DateGenerator::downloadCurrentDate();
        incomeDate = DateGenerator::convertDateToInt(date);
        income.setIncomeDate(incomeDate);
        cout << endl << "Current date is: " << date << endl;
    } else {
        do {
            cout << endl << "Enter again date in format (yyyy-mm-dd)," \
                 "where 'y' key stand for year, 'm' key stands for month and 'd' key stands for day: ";
            do {
                date = AuxilaryMethods::loadLines();
            } while (!DateGenerator::checkFormatDate(date));
            incomeDate = DateGenerator::convertDateToInt(date);
            income.setIncomeDate(incomeDate);
        } while ( !DateGenerator::checkDate(date) );
    }
    cout << endl << "Enter a type of income: ";
    item = AuxilaryMethods::loadLines();
    income.setItem(AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(item));
    cout << endl << "Enter amount of the income: ";
    income.setAmount(AuxilaryMethods::loadNonNegativeFloatingPointNumber());

    cout << income.getUserId() << endl;
    cout << income.getIncomeId() << endl;
    cout << income.getIncomeDate() << endl;
    cout << income.getItem() << endl;
    cout << income.getAmount() << endl;

    return income;
}

void BudgetManager::loadUserIncomes() {
    incomes = incomeFile.loadUserIncomes(LOGGED_USER_ID);
}

void BudgetManager::addExpense() {

    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterNewExpense();

    expenses.push_back(expense);

    if ( expenseFile.addExpenseToFile(expense) )
        cout << endl << "New expense has been added." << endl;
    else
        cout << "Error! Failed to add new expense to file." << endl;
    system("pause");
}

Expense BudgetManager::enterNewExpense() {
    Expense expense;
    string date = "", item = "";
    int expenseDate = 0;

    expense.setExpenseId(expenseFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    char key = ' ';
    cout << "Does the expense relate to today?" << endl;
    cout << "Type 'y' key if yes or other key if no. (y/other key)... ";

    key = tolower(AuxilaryMethods::loadCharacter());

    if (key == 'y') {
        date = DateGenerator::downloadCurrentDate();
        expenseDate = DateGenerator::convertDateToInt(date);
        expense.setExpenseDate(expenseDate);
        cout << endl << "Current date is: " << date << endl;
    } else {
        do {
            cout << endl << "Enter again date in format (yyyy-mm-dd)," \
                 "where 'y' key stand for year, 'm' key stands for month and 'd' key stands for day: ";
            do {
                date = AuxilaryMethods::loadLines();
            } while (!DateGenerator::checkFormatDate(date));
            expenseDate = DateGenerator::convertDateToInt(date);
            expense.setExpenseDate(expenseDate);
        } while ( !DateGenerator::checkDate(date) );

    }
    cout << "Enter a type of expense: ";
    item = AuxilaryMethods::loadLines();
    expense.setItem(AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(item));
    cout << "Enter amount of the expense: ";
    expense.setAmount(AuxilaryMethods::loadNonNegativeFloatingPointNumber());

    cout << expense.getUserId() << endl;
    cout << expense.getExpenseId() << endl;
    cout << DateGenerator::convertIntToDate( expense.getExpenseDate() ) << endl;
    cout << expense.getItem() << endl;
    cout << expense.getAmount() << endl;

    return expense;
}

void BudgetManager::loadUserExpenses() {
    expenses = expenseFile.loadUserExpenses(LOGGED_USER_ID);
}

void BudgetManager::showIncomes() {
    system("cls");
    cout << "             >>> INCOMES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!incomes.empty()) {
        for (int i = 0; i < (int) incomes.size(); i++) {
            displayIncomeData(incomes[i]);
            //cout << endl;
        }
    } else {
        cout << endl << "The income list is empty." << endl << endl;
    }
    //system("pause");
}

void BudgetManager::displayIncomeData(Income income) {
    cout << endl << "Income id:     " << income.getIncomeId()                               << endl;
    cout << "Date:          " << DateGenerator::convertIntToDate(income.getIncomeDate())    << endl;
    cout << "Item:          " << income.getItem()                                           << endl;
    cout << "Amount:        " << fixed << setprecision(2) << income.getAmount()             << endl;
}

void BudgetManager::showExpenses() {
    cout << endl << "             >>> EXPENSES <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    if (!expenses.empty()) {
        for (int i = 0; i < (int) expenses.size(); i++) {
            displayExpenseData(expenses[i]);
        }
    } else {
        if (!incomes.empty()) {
            cout << endl;
        }
        cout << "The expense list is empty." << endl << endl;
    }
    system("pause");
}

void BudgetManager::displayExpenseData(Expense expense) {
    cout << endl << "Expense id:    " << expense.getExpenseId()                             << endl;
    cout << "Date:          " << DateGenerator::convertIntToDate(expense.getExpenseDate())  << endl;
    cout << "Item:          " << expense.getItem()                                          << endl;
    cout << "Amount:        " << fixed << setprecision(2) << expense.getAmount()            << endl;
}

void BudgetManager::showCashBalance() {
    double sumIncomes = 0.0, sumExpenses = 0.0, totalCash = 0.0;

    cout << endl << "             >>> CASH BALANCE <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < (int) incomes.size(); i++) {
        sumIncomes += incomes[i].getAmount();
    }

    for (int i = 0; i < (int) expenses.size(); i++) {
        sumExpenses += expenses[i].getAmount();
    }

    totalCash = sumIncomes - sumExpenses;
    cout << "THE CASH BALANCE IS: " << fixed << setprecision(2) << totalCash << endl << endl;
}
