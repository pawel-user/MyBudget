#include "IncomeFile.h"

int IncomeFile::getLastIncomeId() {
    return lastIncomeId;
}

void IncomeFile::setLastIncomeId(int currentLastIncomeId) {
    if (currentLastIncomeId >= 0)
        lastIncomeId = currentLastIncomeId;
}

bool IncomeFile::addIncomeToFile(Income income) {
    CMarkup xml;
    bool fileExists = false;
    bool fileSaved = false;

    fileExists = xml.Load( loadFilename() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", to_string(income.getIncomeId()));
    xml.AddElem("UserId", to_string(income.getUserId()));
    xml.AddElem("IncomeDate", DateGenerator::convertIntToDate( income.getIncomeDate() ));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", to_string(income.getAmount()));
    xml.ResetPos();

    fileSaved = xml.Save( loadFilename() );

    if (fileSaved == true) {
        setLastIncomeId(getLastIncomeId() + 1);
        return true;
    } else {
        return false;
    }
}

vector <Income> IncomeFile::loadUserIncomes(int loggedUserId) {
    CMarkup xml;
    vector <Income> incomes;
    Income income;
    bool fileExists = false;
    int userId = 0;
    string fileName = loadFilename();

    //xml.Load(fileName);

    fileExists = xml.Load(fileName);

    if ( !fileExists ) {
        cout << "Failed to open xml format file \"" << fileName << "\" and load data." << endl;

        if ( isFileEmpty() )
        cout << "File \"" << fileName << "\" is empty. No data on file." << endl << endl;

    } else {
        cout << "File \"" << fileName << "\" uploaded successfully." << endl << endl;
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            MCD_STR strUserId = xml.GetData();
            userId = stoi( strUserId );

            if (userId == loggedUserId) {
                income.setUserId(userId);
                xml.ResetMainPos();

                xml.FindElem("IncomeId");
                MCD_STR strIncomeId = xml.GetData();
                income.setIncomeId( DateGenerator::convertDateToInt(strIncomeId) );
                xml.ResetChildPos();

                xml.FindElem("Date");
                MCD_STR strDate = xml.GetData();
                income.setIncomeDate(stoi(strDate));
                xml.ResetChildPos();

                xml.FindElem("Item");
                MCD_STR strItem = xml.GetData();
                income.setItem(strItem);
                xml.ResetChildPos();

                xml.FindElem("Amount");
                double amount = stod( MCD_2PCSZ(xml.GetData()) );
                income.setAmount(amount);
                xml.ResetMainPos();

                incomes.push_back(income);
                lastIncomeId = income.getIncomeId();
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}
