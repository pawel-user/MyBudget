#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    if(newIncomeId >= 0)
        incomeId = newIncomeId;
}

void Income::setUserId(int newUserId)
{
    if(newUserId >= 0)
        userId = newUserId;
}

void Income::setIncomeDate(int newIncomeDate)
{
    if(newIncomeDate >= 0)
        incomeDate = newIncomeDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(double newAmount)
{
    if(newAmount >= 0.0)
        amount = newAmount;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getUserId()
{
    return userId;
}

int Income::getIncomeDate()
{
    return incomeDate;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}
