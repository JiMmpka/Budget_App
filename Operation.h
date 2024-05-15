#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

#include "Type.h"

using namespace std;

struct Operation{
private:
    int id;
    int userId;
    string date;
    string item;
    string amount;
    Type operationType;

public:
    Operation(int id = 0, int userId = 0, string date = "", string item = "", string amount = "", Type operationType = INCOME){
    this -> id = id;
    this -> userId = userId;
    this -> date = date;
    this -> item = item;
    this -> amount = amount;
    this -> operationType = operationType;
    }

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string &newDate);
    void setItem(string &newItem);
    void setAmount(string &newAmount);
    void setOperationType(Type newOperationType);

    int getId()const;
    int getUserId()const;
    string getDate()const;
    string getItem()const;
    string getAmount()const;
    Type getOperationType() const;
};
#endif
