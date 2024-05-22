#include "OperationFile.h"

vector <Operation> OperationFile::loadOperationsFromFile (const int loggedUserId){
    vector <Operation> operations;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists){
        return operations;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem()) {
        Operation operation;

        xml.FindChildElem("Id");
        operation.setId(stoi(xml.GetChildData()));
        lastOperationId = operation.getId();

        if (xml.FindChildElem("UserId") == loggedUserId){
            operation.setUserId(stoi(xml.GetChildData()));
            xml.FindChildElem("Date");
            operation.setDate(stoi(xml.GetChildData()));
            xml.FindChildElem("Item");
            operation.setItem(xml.GetChildData());
            xml.FindChildElem("Amount");
            operation.setAmount(stod(xml.GetChildData()));

            operations.push_back(operation);
        }
    }
    return operations;
}

bool OperationFile::addOperationToFile (const Operation & operation){
    bool fileExists = xml.Load(getFileName());
    ostringstream oss;

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
    oss << fixed << setprecision(2) << operation.getAmount();
    xml.AddElem("Amount", oss.str());

    xml.Save(getFileName());

    return 0;
}

int OperationFile::getLastOperationId(){
    return lastOperationId;
}
