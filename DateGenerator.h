#ifndef DATEGENERATOR_H
#define DATEGENERATOR_H

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

struct MyDate;

class DateGenerator {
public:
    struct MyDate {
        string year;
        string month;
        string day;
    };
    MyDate myDate;

    bool checkYear(string date);
    bool checkMonth(string date);
    bool checkDay(string date);
    static bool checkIfYearIsLeap(int year);
    static int howManyDaysInMonth(int month, int year);
    MyDate breakDateIntoComponents(string date);

public:
    DateGenerator(string year = "0000", string month = "00", string day = "00") {
        this->myDate.year = year;
        this->myDate.month = month;
        this->myDate.day = day;
    };

    static string downloadCurrentDate();
    static bool checkDate(string date);
    static bool checkFormatDate(string date);
    static int convertDateToInt(string date);
    static string convertIntToDate(int number);
};

#endif  //DATEGENERATOR_H
