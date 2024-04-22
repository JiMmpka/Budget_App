#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include "Markup.h"

using namespace std;

class File{
    const string FILE_NAME;

protected:
    int lastId;
    CMarkup xmlDoc;
    void checkRootNode();
    bool isFileEmpty();

public:
    File(string FileName) : FILE_NAME(FileName){};
    string getFileName();
};
#endif // PLIKTEKSTOWY_H
