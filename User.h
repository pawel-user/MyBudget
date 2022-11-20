#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string firstName;
    string lastName;
    string login;
    string password;

public:
    User(int id = 0, string firstName = "", string lastName = "", string login = "", string password = "") {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->login = login;
        this->password = password;
    };

    void setId(int newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getFirstName();
    string getLastName();
    string getLogin();
    string getPassword();
};

#endif
