#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include <conio.h>

using namespace std;

class AuxilaryMethods {
public:
    static string loadLines();
    static char loadCharacter();
    static string changeTheFirstLetterToUppercaseAndTheOthersToLowercase(string text);
    static double loadNonNegativeFloatingPointNumber();
    static string formatCashAmount(string cashAmount);
    static double roundToSpecifiedNumberOfDecimalPlaces(double number, int decimalPlaces);
    static void writeAndClearText(string text);
};

#endif //AUXILARYMETHODS_H
