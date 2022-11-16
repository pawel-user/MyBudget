#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int incomeDate;
    string item;
    double amount;

public:
    Income(int incomeId = 0, int userId = 0, int incomeDate = 0, string item = "", double amount = 0.0) {
        this->incomeId = incomeId;
        this->userId = userId;
        this->incomeDate = incomeDate;
        this->item = item;
        this->amount = amount;
    };

    bool operator < (const Income& income) const {
        return (incomeDate < income.incomeDate);
    }

    void setIncomeId(int setIncomeId);
    void setUserId(int userId);
    void setIncomeDate(int incomeDate);
    void setItem(string item);
    void setAmount(double amount);

    int getIncomeId();
    int getUserId();
    int getIncomeDate();
    string getItem();
    double getAmount();
};

#endif //INCOME_H
