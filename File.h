#ifndef FILE_H
#define FILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class File{
    const string FILE_NAME;

protected:
    int lastId;
    CMarkup xml;

    File(const string FileName) : FILE_NAME(FileName){};

    string getFileName();
};
#endif
