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
    int lastIncomeId;

public:
    OperationFile(const string FileName) : File(FileName){};

    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation & operation);
};
#endif
