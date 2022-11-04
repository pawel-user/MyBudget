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

    };
    //friend class MyBudget;
    void registerUser();
    void logInUser();

    int getLoggedUserId();
    void setLoggedUserId(int newLoggedUserId);
    friend int _main();
};

#endif // USERMANAGER_H
