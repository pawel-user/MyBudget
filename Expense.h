#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    int expenseDate;
    string item;
    double amount;

public:
    Expense(int expenseId = 0, int userId = 0, int expenseDate = 0, string item = "", double amount = 0.0) {
        this->expenseId = expenseId;
        this->userId = userId;
        this->expenseDate = expenseDate;
        this->item = item;
        this->amount = amount;
    };

    bool operator < (const Expense& expense) const {
        return (expenseDate < expense.expenseDate);
    }

    void setExpenseId(int setExpenseId);
    void setUserId(int userId);
    void setExpenseDate(int expenseDate);
    void setItem(string item);
    void setAmount(double amount);

    int getExpenseId();
    int getUserId();
    int getExpenseDate();
    string getItem();
    double getAmount();
};

#endif //EXPENSE_H
