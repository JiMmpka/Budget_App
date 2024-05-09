#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>//TO DOO check if all includes are necessary
#include <fstream>
#include <sstream>
#include <string>

#include "User.h"
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager{
    int loggedUserId;
    vector <User> users;
    UserFile userFile;

    bool isLoginExist(const string &login);
    User enterNewUserData();
    int getNewUserId();
    //void FindUserByLogin (const string  & login, vector <User>:: iterator &itr);
    //void findUserById(vedtor <User>::iterator &itr);

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
