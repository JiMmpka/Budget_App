#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    bool isLoginExist(const string &login);
    User enterNewUserData();
    int getNewUserId();

public:
    UserManager(string userFileName) : userFile(userFileName){
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    };
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void logoutUser();
    int getLoggedUserId();
};

#endif
