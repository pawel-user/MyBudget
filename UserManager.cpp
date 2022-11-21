#include "UserManager.h"

bool UserManager::ifUserLoggedIn() {
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::displayMainMenu() {
    system("cls");
    cout << "    >>> MAIN MENU <<<"         << endl;
    cout << "---------------------------"   << endl;
    cout << "1. Register"                   << endl;
    cout << "2. LogIn"                      << endl;
    cout << "---------------------------"   << endl;
    cout << "9. Exit"                       << endl;
    cout << "---------------------------"   << endl << endl;
}

char UserManager::chooseOptionFromMainMenu() {
    char choice;
    displayMainMenu();
    cout << "Your choice: ";
    choice = AuxilaryMethods::loadCharacter();
    displayMainMenu();
    return choice;
}

void UserManager::registerUser() {
    User user = enterNewUserData();
    if (user.getId() != 0) {
        users.push_back(user);
        userFile.addUserToFile(user);

        cout << "The account was created successfully." << endl << endl;
        system("pause");
        cin.sync();
    }
}

User UserManager::enterNewUserData() {
    User user;

    user.setId(downloadNewUserId());

    string name = "", surname = "";

    system("cls");
    cout << "    >>> NEW USER REGISTRATION <<<"         << endl;
    cout << "---------------------------------------"   << endl;
    cout << "Enter name: ";
    name = AuxilaryMethods::loadLines();
    name = AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(name);
    user.setFirstName(name);
    cout << "Enter surname: ";
    surname = AuxilaryMethods::loadLines();
    surname = AuxilaryMethods::changeTheFirstLetterToUppercaseAndTheOthersToLowercase(surname);
    user.setLastName(surname);
    if (ifUserExists(user.getFirstName(), user.getLastName()) == true) {
        cout << endl << "New user registration cancelled." << endl;
        user.setId(0);
        Sleep(1500);
        system("cls");
        return user;
    }

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

            if (key == 'y') {
                cout << endl;
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
        system("cls");
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
    cout << endl;
    do {
        system("cls");
        cout << "    >>> USER LOGGING <<<"        << endl;
        cout << "-----------------------------"   << endl;
        cout << "Enter login: ";
        login = AuxilaryMethods::loadLines();
    } while (ifLoginCorrect(login) == false);

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl;
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Enter password. Remaining trails: " << numberOfAttempts << ": ";
                password = AuxilaryMethods::loadLines();

                if (users[i].getPassword() == password) {
                    loggedUserId = users[i].getId();
                    cout << endl << "You have successfully logged in." << endl << endl;
                    system("pause");
                    return;
                } else {
                    cout << "Password is incorrect." << endl << endl;
                    system("pause");

                }
            }
            displayMainMenu();
            cout << "You entered the wrong password three times." << endl << endl;
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
    return false;
}

void UserManager::setLoggedUserId(int newLoggedUserId) {
    if(newLoggedUserId >= 0)
        loggedUserId = newLoggedUserId;
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::logOutUser() {
    loggedUserId = 0;
    cout << "You have successfully logged out." << endl;
}

void UserManager::changeUserPassword() {
    string newPassword = "";
    do {
        system("cls");
        cout << "    >>> CHANGING USER PASSWORD <<<"        << endl;
        cout << "---------------------------------------"   << endl;
        cout << endl << "Enter a new password: ";
        newPassword = AuxilaryMethods::loadLines();
    } while ( !ifPasswordCorrect(newPassword) );

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getId() == loggedUserId) {
            users[i].setPassword(newPassword);
            cout << endl << "Password has been changed correctly." << endl;
            system("pause");
        }
    }
    userFile.saveAllUsersToFile(users);
}
