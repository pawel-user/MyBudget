#include "DateGenerator.h"
#include "MyBudget.h"

string DateGenerator::downloadCurrentDate() {
    SYSTEMTIME st;
    GetSystemTime(&st);
    string currentDate = "00-00-00";
    string currentYear = "0000";
    string currentMonth = "00";
    string currentDay = "00";
    const int LAST_SINGLE_DIGIT = 9;


    currentYear = to_string(st.wYear);

    if (st.wMonth > LAST_SINGLE_DIGIT) {
        currentMonth = to_string(st.wMonth);
    } else {
        currentMonth = "0" + to_string(st.wMonth);
    }

    if (st.wDay > LAST_SINGLE_DIGIT) {
        currentDay = to_string(st.wDay);
    } else {
        currentDay = "0" + to_string(st.wDay);
    }
    currentDate = currentYear + "-" + currentMonth + "-" + currentDay;

    return currentDate;
}

bool DateGenerator::checkYear(string date) {
    int year = 0;
    SYSTEMTIME st;
    GetSystemTime(&st);
    const int LOWER_LIMIT_OF_YEAR = 2000;

    breakDateIntoComponents(date);
    year = stoi(myDate.year);

    if ((year >= LOWER_LIMIT_OF_YEAR) && (year <= st.wYear)) {
        return true;
    } else {
        return false;
    }
}

bool DateGenerator::checkMonth(string date) {
    int month = 0;
    SYSTEMTIME st;
    GetSystemTime(&st);
    const int UPPER_LIMIT_OF_MONTH = 12;

    month = stoi(myDate.month);

    if ((month <= UPPER_LIMIT_OF_MONTH) && (month > 0)) {
        return true;
    } else {
        return false;
    }
}

bool DateGenerator::checkDay(string date) {
    int day = 0, month = 0, year = 0;
    SYSTEMTIME st;
    GetSystemTime(&st);

    year = stoi(myDate.year);
    month = stoi(myDate.month);
    day = stoi(myDate.day);

    const int UPPER_LIMIT_OF_DAY = howManyDaysInMonth(month, year);

    if ((day <= UPPER_LIMIT_OF_DAY) && (day > 0)) {
        return true;
    } else {
        return false;
    }
}

bool DateGenerator::checkDate(string date) {
    DateGenerator dateGenerator;
    BudgetManager *manager = NULL;

    for (int i = 0; i < (int) date.size(); i++) {
        if ((date[i] < '0' && date[i] != '-') || (date[i] > '9')) {
            system("cls");
            manager->displayUserMenu();
            cout << "Incorrect data entered. Try again." << endl;
            return false;
        }
    }

    if (dateGenerator.checkYear(date) && dateGenerator.checkMonth(date) && dateGenerator.checkDay(date)) {
        return true;
    } else {
        system("cls");
        manager->displayUserMenu();
        cout << "The date given is incorrect or out of range." << endl;
    }
    return false;
}

bool DateGenerator::checkIfYearIsLeap(int year) {
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
        return true;
    else
        return false;
}

int DateGenerator::howManyDaysInMonth(int month, int year) {
    int numberDaysInMonth = 0;

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        numberDaysInMonth = 30;
    } else if(month == 2) {
        if(checkIfYearIsLeap(year)) {
            numberDaysInMonth = 29;
        } else {
            numberDaysInMonth = 28;
        }
    } else {
        numberDaysInMonth = 31;
    }

    return numberDaysInMonth;
}

DateGenerator::MyDate DateGenerator::breakDateIntoComponents(string date) {
    int numberOfHyphenFound = 0;

    SYSTEMTIME st;
    GetSystemTime(&st);

    for (int i = 0; i < (int) date.size(); i++) {
        if ((date[i] != '-') && (numberOfHyphenFound == 0)) {
            myDate.year += date[i];
        } else if ((date[i] != '-') && (numberOfHyphenFound == 1)) {
            myDate.month += date[i];
        } else if ((date[i] != '-') && (numberOfHyphenFound == 2)) {
            myDate.day += date[i];
        } else if ((date[i] == '-')) {
            numberOfHyphenFound++;
        }
    }
    return myDate;
}

int DateGenerator::convertDateToInt(string date) {
    string numericString = "";
    int numberIndicatingDate = 0;

    for (int i = 0; i < (int) date.size(); i++) {
        if ((date[i] != '-')) {
            numericString += date[i];
        }
    }
    numberIndicatingDate = stoi(numericString);

    return numberIndicatingDate;
}

string DateGenerator::convertIntToDate(int number) {
    string year = "", month = "", day = "", strNumber = "";
    string formatDate = "";

    strNumber = to_string(number);
    int numberLength = (int) strNumber.size();

    for (int i = 0; i < numberLength; i++) {
        if (i == 4) {
            year = formatDate;
            formatDate = "";
        } else if(i == 6) {
            month = formatDate;
            formatDate = "";
        } else if(i == (numberLength - 1)) {
            formatDate += strNumber[i];
            day = formatDate;
        }
        formatDate += strNumber[i];
    }
    formatDate = "";
    formatDate = year + "-" + month + "-" + day;
    return formatDate;
}

bool DateGenerator::checkFormatDate(string date) {
    BudgetManager *manager = NULL;
    bool correctFormatDate = true;
    const int DATE_LENGTH_IN_GIVEN_FORMAT = 10;
    int numberOccurrencesOfHyphen = 0;
    int dateLength = (int) date.size();

    if (dateLength != DATE_LENGTH_IN_GIVEN_FORMAT) {
        correctFormatDate = false;
    } else {
        for (int i = 0; i < dateLength; i++) {
            if ( (date[i] < '0' && date[i] != '-') || date[i] > '9' ) {
                correctFormatDate = false;
                break;
            } else if (date[i] == '-') {
                numberOccurrencesOfHyphen++;
            }
        }
        if (numberOccurrencesOfHyphen != 2) {
            correctFormatDate = false;
        }
    }

    if (!correctFormatDate) {
        system("cls");
        manager->displayUserMenu();
        cout << "Incorrect format date entered. Try again." << endl;
        cout << "Type only numbers and key \"-\" in correct format (yyyy-mm-dd)" << endl << endl;
        return false;
    }

    return true;
}
