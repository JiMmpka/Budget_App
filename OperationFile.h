#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include <vector>
#include <iomanip>

#include "Operation.h"
#include "File.h"

using namespace std;

class OperationFile : public File{
    int lastOperationId;

public:
    OperationFile(const string FileName) : File(FileName){
    lastOperationId = 0;
    };

    vector <Operation> loadOperationsFromFile (const int loggedUserId);
    bool addOperationToFile (const Operation & operation);

    int getLastOperationId();
};
#endif
