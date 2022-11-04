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
