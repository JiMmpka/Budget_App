#include "UserManager.h"

void UserManager::registerUser(){
    User user = enterNewUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << "\nAcount sucsessfully created\n\n";
    system("pause");
}

User UserManager::enterNewUserData(){
    User user;
    string name = "";    string surname = "";
    string login = "";
    string password = "";

    cout << "Enter name: ";
    name = Utils::readLine();
    user.setName(name);

    cout << "Enter surname: ";
    surname = Utils::readLine();
    user.setSurname(surname);
    user.setId(getNewUserId());

    do{
        cout << "Enter login: ";
        login = Utils::readLine();
        user.setLogin(login);
    }
    while(Utils::validateInput(user.getLogin()) || (isLoginExist(user.getLogin())));

    do{
        cout << "Enter password: ";
        password = Utils::readLine();
        user.setPassword(password);
    }
    while(Utils::validateInput(user.getPassword()));

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(const string &login){
    for (size_t i = 0; i < users.size(); i++){
        if (users[i].getLogin() == login){
            cout << "\nThere is a user with this login.\n";
            return true;
        }
    }
    return false;
}

void UserManager::loginUser(){
    User user;
    string login = "", password = "";
    vector <User>::iterator itr = users.begin();

    if(users.empty()){
        cout << "Please register first.\n";
        system("pause");
        return;
    }

    cout << "\nEnter login: ";
    login = Utils::readLine();

    while (itr != users.end()){
        if (itr -> getLogin() == login){
            for (int attempt = 3; attempt > 0; attempt--){
                cout << "Enter password. Trials remaining: " << attempt << ": ";
                password = Utils::readLine();

                if (itr -> getPassword() == password){
                    loggedUserId = itr -> getId();
                    cout << "\nYou logged in.\n\n";
                    system("pause");
                    return;
                }
            }
            cout << "Wrong password entered 3 times.\n";
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such a login\n\n";
    system("pause");
    return;
}

void UserManager::changeLoggedInUserPassword(){
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = Utils::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        if (itr -> getId() == loggedUserId)
            itr -> setPassword(newPassword);
    }

    string result = userFile.changePasswordInFile(loggedUserId, newPassword) ? "The password has been changed.\n\n" : "The password has not been changed couse there is no xml file\n\n";
    cout << result;

    system("pause");
}

void UserManager::logoutUser(){
    loggedUserId = 0;
    cout << "\nYou logged out.\n\n";
    system("pause");
}

bool UserManager::isUserLoggedIn(){
    if(loggedUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLoggedUserId(){
    return loggedUserId;
}
