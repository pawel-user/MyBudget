#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <string>

#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile : public XmlFile {

public:
    UserFile(string userFilename) : XmlFile(userFilename) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
};

#endif // USERFILE_H
