#include "AuxilaryMethods.h"

string AuxilaryMethods::loadLines()
{
    string exit = "";
    getline(cin, exit);
    return exit;
}

char AuxilaryMethods::loadCharacter()
{
    string enter = "";
    char character  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            character = enter[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}

string AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

/*string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}*/


