#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UserFile.h"
#include "AuxilaryMethods.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    User enterNewUserData();
    int downloadNewUserId();
    bool ifUserExists(string name, string surname);
    bool ifLoginExists(string login);
    bool ifLoginCorrect(string login);
    bool ifPasswordCorrect(string password);
    bool ifPasswordLongEnough(string password);
    bool ifPasswordHasUpperCaseLetter(string password);
public:
    UserManager(string userFilename)
        : userFile(userFilename) {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    bool ifUserLoggedIn();
    char chooseOptionFromMainMenu();
    void displayMainMenu();

    void registerUser();
    void logInUser();
    void logOutUser();
    void changeUserPassword();

    int getLoggedUserId();
    void setLoggedUserId(int newLoggedUserId);
};

#endif // USERMANAGER_H
