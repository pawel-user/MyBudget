#include "UserFile.h"

void UserFile::addUserToFile(User user) {

    CMarkup xml;
    bool fileExists;

    fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
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

    xml.Save("users.xml");

    return;
}

vector <User> UserFile::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector <User> users;
    bool fileExists;

    fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        cout << "Failed to open xml format file and load data." << endl;
    } else {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            //users[index] = atoi( MCD_2PCSZ(xml.GetData()) );
            user.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
            xml.ResetMainPos();

            xml.FindElem("FirstName");
            //MCD_STR firstName = xml.GetData();
            user.setFirstName(xml.GetData());
            xml.ResetMainPos();

            xml.FindElem("LastName");
            //MCD_STR strSURNAME = xml.GetData();
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
