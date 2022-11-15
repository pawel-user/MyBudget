#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Expense.h"
#include "Markup.h"
#include "DateGenerator.h"

using namespace std;

class ExpenseFile : public XmlFile {
private:
    int lastExpenseId;

public:
    ExpenseFile(string expenseFilename) : XmlFile(expenseFilename) {
        lastExpenseId = 0;
    };

    bool addExpenseToFile(Expense expense);
    vector <Expense> loadUserExpenses(int loggedUserId);

    int getLastExpenseId();
    void setLastExpenseId(int currentLastExpenseId);
};

#endif // EXPENSEFILE_H
