#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    CMarkup xml;
    bool fileExists;

    fileExists = xml.Load( loadFilename() );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("FirstName", user.getFirstName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.ResetPos();

    xml.Save(loadFilename());

    return;
}

vector <User> UserFile::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector <User> users;
    bool fileExists;

    fileExists = xml.Load( loadFilename() );

    //if (!fileExists) {
    //cout << "Failed to open xml format file and load data." << endl;
    //cout << "File \"" << loadFilename() << "\" is empty or not exist." << endl;
    //} else {
    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.ResetMainPos();

            xml.FindElem("FirstName");
            user.setFirstName(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("LastName");
            user.setLastName(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }
    return users;
}

void UserFile::saveAllUsersToFile(vector <User> users) {
    CMarkup xml;
    bool fileExists;

    fileExists = xml.Load( loadFilename() );

    //if (!fileExists) {
    //cout << "Failed to open xml format file and load data." << endl;
    //} else {
    if (fileExists) {
        while (xml.FindElem()) {
            xml.RemoveElem();
        }
        xml.ResetPos();
        xml.AddElem("Users");
        xml.IntoElem();
        for (int i = 0; i < (int) users.size(); i++) {
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("UserId", to_string(users[i].getId()));
            xml.AddElem("FirstName", users[i].getFirstName());
            xml.AddElem("LastName", users[i].getLastName());
            xml.AddElem("Login", users[i].getLogin());
            xml.AddElem("Password", users[i].getPassword());
            xml.OutOfElem();
        }
    }
    xml.Save( loadFilename() );
}
