#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>

#include "XmlFile.h"
#include "Income.h"
#include "Markup.h"
#include "DateGenerator.h"

using namespace std;

class IncomeFile : public XmlFile {
private:
    int lastIncomeId;

public:
    IncomeFile(string incomeFilename) : XmlFile(incomeFilename) {
        lastIncomeId = 0;
    };

    bool addIncomeToFile(Income income);
    vector <Income> loadUserIncomes(int loggedUserId);

    int getLastIncomeId();
    void setLastIncomeId(int currentLastIncomeId);
};

#endif // INCOMEFILE_H
