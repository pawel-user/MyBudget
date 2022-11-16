#include "ExpenseFile.h"

int ExpenseFile::getLastExpenseId() {
    return lastExpenseId;
}

void ExpenseFile::setLastExpenseId(int currentLastExpenseId) {
    if (currentLastExpenseId >= 0)
        lastExpenseId = currentLastExpenseId;
}

bool ExpenseFile::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = false;
    bool fileSaved = false;

    fileExists = xml.Load( loadFilename() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", to_string(expense.getExpenseId()));
    xml.AddElem("UserId", to_string(expense.getUserId()));
    xml.AddElem("ExpenseDate", DateGenerator::convertIntToDate( expense.getExpenseDate() ));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", to_string(expense.getAmount()));
    xml.ResetPos();

    fileSaved = xml.Save( loadFilename() );

    if (fileSaved == true) {
        setLastExpenseId(getLastExpenseId() + 1);
        return true;
    } else {
        return false;
    }
}

vector <Expense> ExpenseFile::loadUserExpenses(int loggedUserId) {
    CMarkup xml;
    vector <Expense> expenses;
    Expense expense;
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
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            MCD_STR strUserId = xml.GetData();
            userId = stoi( strUserId );

            if (userId == loggedUserId) {
                expense.setUserId(userId);
                xml.ResetMainPos();

                xml.FindElem("ExpenseId");
                MCD_STR strExpenseId = xml.GetData();
                expense.setExpenseId(stoi(strExpenseId));
                xml.ResetChildPos();

                xml.FindElem("ExpenseDate");
                MCD_STR strDate = xml.GetData();
                expense.setExpenseDate( DateGenerator::convertDateToInt(strDate) );
                xml.ResetChildPos();

                xml.FindElem("Item");
                MCD_STR strItem = xml.GetData();
                expense.setItem(strItem);
                xml.ResetChildPos();

                xml.FindElem("Amount");
                double amount = stod( MCD_2PCSZ(xml.GetData()) );
                expense.setAmount(amount);
                xml.ResetMainPos();

                lastExpenseId = expense.getExpenseId();
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
    }
    return expenses;
}
