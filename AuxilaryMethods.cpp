#include "AuxilaryMethods.h"

string AuxilaryMethods::loadLines() {
    string exit = "";
    getline(cin, exit);
    return exit;
}

char AuxilaryMethods::loadCharacter() {
    const string MESSAGE = "This is not a single character. Type again.";
    string enter = "";
    char character  = {0};

    while (true) {
        getline(cin, enter);

        if (enter.length() == 1) {
            character = enter[0];
            break;
        }
        writeAndClearText(MESSAGE);
        cout << "Re-choice: ";
    }
    return character;
}

string AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

double AuxilaryMethods::loadNonNegativeFloatingPointNumber() {
    string enter = "";
    double number = 0.0;
    const int NUMBER_OF_DECIMAL_PLACES_TO_ROUND_UP = 2;
    const string MESSAGE = "This is not a non-negative floating-point number. Type again. ";

    while (true) {
        getline(cin, enter);
        enter = formatCashAmount(enter);

        stringstream myStream(enter);

        if (myStream >> fixed >> setprecision(NUMBER_OF_DECIMAL_PLACES_TO_ROUND_UP) >> number)
            break;
        writeAndClearText(MESSAGE);
    }
    number = roundToSpecifiedNumberOfDecimalPlaces(number, NUMBER_OF_DECIMAL_PLACES_TO_ROUND_UP);

    return number;
}

double AuxilaryMethods::roundToSpecifiedNumberOfDecimalPlaces(double number, int decimalPlaces) {
    number *= pow(10, decimalPlaces);
    number = round(number);
    number /= pow(10, decimalPlaces);

    return number;
}

string AuxilaryMethods::formatCashAmount(string cashAmount) {
    for (int i = 0; i < (int) cashAmount.size(); i++) {
        if (cashAmount[i] == ',') {
            cashAmount[i] = '.';
        }
    }
    return cashAmount;
}

void AuxilaryMethods::writeAndClearText(string text) {
    cout << text;
    Sleep(1000);
    for (int i = 0; i < (int) text.size(); i++) {
        cout << "\b \b";
    }
}
