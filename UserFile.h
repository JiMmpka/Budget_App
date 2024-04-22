#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Utils.h"
#include "File.h"

using namespace std;

class UserFile : public File{
public:
    UserFile(string userFileName) : File(userFileName){};

    bool appendUserToFile(User &user);
    vector <User> loadUsersFromFile();
    User getUsersData(string data);
    bool changePasswordInFile(int userId, string &password);
};
#endif
