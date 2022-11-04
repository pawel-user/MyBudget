#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>

#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile : public XmlFile {
public:
    UserFile(string userFilename) : XmlFile(userFilename) {};
    void addUserToFile(User user);
};

#endif // USERFILE_H
