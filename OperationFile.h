#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <iostream>
#include <vector>
#include <fstream>//TO DOO is this necessary?
#include <cstdlib>//TO DOO is this necessary?

#include "Operation.h"
#include "Utils.h"
#include "File.h"

using namespace std;

class OperationFile : public File{
    int lastOperationId;

public:
    OperationFile(const string FileName) : File(FileName){
    lastOperationId = 0;
    };

    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation & operation);// zapoisywaæ datê w pliku z myœlnikami czy bez?

    int getLastOperationId();
};
#endif
