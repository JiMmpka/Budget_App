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
    CMarkup xml;

    File(string FileName) : FILE_NAME(FileName){};

    void checkRootNode();//TO DOO gdzie tego mam u¿yæ?
    string getFileName();
};
#endif
