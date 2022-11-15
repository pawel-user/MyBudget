#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

class AuxilaryMethods
{
public:
    //static string konwersjaIntNaString(int liczba);
    //static int konwersjaStringNaInt(string liczba);
    static string loadLines();
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char loadCharacter();
    static string changeTheFirstLetterToUppercaseAndTheOthersToLowercase(string text);
    static double loadNonNegativeFloatingPointNumber();
    static string replaceCommaWithDot(string text);
    static double roundToSpecifiedNumberOfDecimalPlaces(double number, int decimalPlaces);
    //static int wczytajLiczbeCalkowita();
};

#endif //AUXILARYMETHODS_H
