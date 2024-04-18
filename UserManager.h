#ifndef UZYTKOWNIKMENEGER_H
#define UZYTKOWNIKMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>

//#include "User.h"
//#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager{
    int loggedUserId;
    //vector <User> users;
//    UserFile userFile;
    const string TEMP;//>>TEMP LINE FOR TESTS<<

    bool checkIfLoginExist(const string &login);
//    User enterNewUserData();
    int getNewUserId();
    bool ifLoginExist(string login);
    //void FindUserByLogin (const string  & login, vector <User>:: iterator &itr);
    //void findUserById(vedtor <User>::iterator &itr);

public:
    UserManager(string userFileName) : TEMP(userFileName){
        loggedUserId = 0;
       // users = UserFile.loadUsersFromFile();
        };
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void logoutUser();
};

#endif
