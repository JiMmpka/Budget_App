#include "UserFile.h"

vector <User> UserFile::loadUsersFromFile(){
    vector <User> users;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists){
        return users;
    }

    xml.ResetPos();
    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User")) {
        User user;

        xml.FindChildElem("UserId");
        user.setId(stoi(xml.GetChildData()));
        xml.FindChildElem("Login");
        user.setLogin(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setPassword(xml.GetChildData());
        xml.FindChildElem("Name");
        user.setName(xml.GetChildData());
        xml.FindChildElem("Surname");
        user.setSurname(xml.GetChildData());

        users.push_back(user);
    }

    return users;
}

bool UserFile::appendUserToFile(User &user){
    //CMarkup xml; //TO DOO - already created in File.h

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");

    return 0;
}


bool UserFile::changePasswordInFile(int userId, string &password){

}
