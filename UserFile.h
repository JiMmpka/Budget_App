#ifndef USERFILE_H
#define USERFILE_H

#include <vector>

#include "User.h"
#include "Utils.h"
#include "File.h"

using namespace std;

class UserFile : public File{
public:
    UserFile(string userFileName) : File(userFileName){};

    vector <User> loadUsersFromFile();
    bool appendUserToFile(User &user);
    bool changePasswordInFile(int userId, string &password);
};
#endif
