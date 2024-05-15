#include "OperationFile.h"

vector <Operation> OperationFile::loadOperationsFromFile (const int loggedUserId){}

bool OperationFile::addOperationToFile (const Operation & operation){
    bool fileExists = xml.Load(getFileName());

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        if (operation.getOperationType() == INCOME)
            xml.AddElem("Incomes");
        else xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();

    if (operation.getOperationType() == INCOME)
        xml.AddElem("Income");
    else xml.AddElem("Expense");

    xml.IntoElem();
    xml.AddElem("Id", operation.getId());
    xml.AddElem("UserId", operation.getUserId());
    xml.AddElem("Date", operation.getDate());
    xml.AddElem("Item", operation.getItem());
    xml.AddElem("Amount", operation.getAmount());

    xml.Save(getFileName());

    return 0;
}
