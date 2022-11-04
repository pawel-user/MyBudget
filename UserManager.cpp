#include "UserManager.h"

void UserManager::registerUser() {
    //for (int i = 0; i < 2; i++) {
    User user = enterNewUserData();
    //User user(1, "Rob", "Gryn", "rob", "Robman123");
    users.push_back(user);
    //}
    userFile.addUserToFile(user);

    cout << endl << "The account was created successfully." << endl << endl;
    system("pause");
    cin.sync();
}

User UserManager::enterNewUserData() {
    User user;

    user.setId(downloadNewUserId());

    string name = "", surname = "";
    do {
        cout << "Enter name: ";
        name = AuxilaryMethods::loadLines();
        name = AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(name);
        user.setFirstName(name);
        cout << "Enter surname: ";
        surname = AuxilaryMethods::loadLines();
        surname = AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(surname);
        user.setLastName(surname);
    } while (ifUserExists(user.getFirstName(), user.getLastName()) == true);

    string login;
    cout << "Enter login: ";
    login = AuxilaryMethods::loadLines();
    user.setLogin(login);

    string password;
    do {
        cout << "Enter password: ";
        password = AuxilaryMethods::loadLines();
        user.setPassword(password);
        system("cls");
    } while ( ifPasswordCorrect(user.getPassword()) == false );

    return user;
}

int UserManager::downloadNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::ifUserExists(string name, string surname) {
    char key = ' ';

    for (int i = 0; i < (int) users.size(); i++) {
        if ( (users[i].getFirstName() == name) && (users[i].getLastName() == surname) ) {
            cout << endl << "A user with this name and surname already exists." << endl;
            cout << endl << "Are you sure you want to register under this name?" << endl;
            cout << "Press 'y' key if you confirm or 'n' key if you want to cancel (y/n)... ";

            key = tolower(AuxilaryMethods::loadCharacter());

            if (key == 'Y') {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}

bool UserManager::ifLoginExists(string login) {
    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "A user with this login already exists." << endl;
            cout << "Enter a different login." << endl;
            system("pause");
            cout << endl;
            return true;
        }
    }
    return false;
}

bool UserManager::ifPasswordCorrect(string password) {
    if ( (ifPasswordLongEnough(password) == true) && (ifPasswordHasUpperCaseLetter(password) == true) )
        return true;
    else {
        cout << "Password is incorrect." << endl << endl;
        cout << "Your password should be at least 5 characters long " << '\n' << "and has at least one uppercase letter. " << endl;
        cout << endl << "Try again..." << endl << endl;
        system("pause");
        cout << endl;
        return false;
    }
}

bool UserManager::ifPasswordLongEnough(string password) {

    const int MINIMUM_PASSWORD_LENGTH = 5;
    if ( (int) password.size() >= MINIMUM_PASSWORD_LENGTH) {
        return true;
    } else {
        return false;
    }
}

bool UserManager::ifPasswordHasUpperCaseLetter(string password) {
    for (int i = 0; i < (int) password.size(); i++) {
        if ((password[i] >= 'A' && password[i] <= 'Z')) {
            return true;
        }
    }
return false;
}

void UserManager::logInUser() {
    string login = "", password = "";

    do {
        cout << "Enter login: ";
        login = AuxilaryMethods::loadLines();
    } while (ifLoginCorrect(login) == false);

    for (int i = 0; i < (int) users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << endl << "Enter password. Remaining trails: " << numberOfAttempts << ": ";
                password = AuxilaryMethods::loadLines();

                    if (users[i].getPassword() == password)
                    {
                        loggedUserId = users[i].getId();
                        cout << endl << "You have successfully logged in." << endl << endl;
                        system("pause");
                        return;
                    } else {
                        cout << "Password is incorrect (" << numberOfAttempts << " attempts remain)" << endl;
                    }
            }
            cout << endl << "You entered the wrong password three times." << endl;
            system("pause");
            return;
        }
    }
}

bool UserManager::ifLoginCorrect(string login) {
    for (int i = 0; i < (int) users.size(); i++) {
        if ( login  == users[i].getLogin() ) {
            return true;
        }
    }
    cout << endl << "There is no such user." << endl;
    system("pause");
    system("cls");
    return false;
}
