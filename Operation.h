#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

#include "Type.h"

using namespace std;

struct Operation{
private:
    int id;
    int userId;
    int date;
    string item;
    double amount;
    Type operationType;

public:
    Operation(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0.0, Type operationType = INCOME)
        : id(id), userId(userId), date(date), item(item), amount(amount), operationType(operationType) {}

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(const int &newDate);
    void setItem(const string &newItem);
    void setAmount(const double &newAmount);
    void setOperationType(Type newOperationType);

    int getId() const;
    int getUserId() const;
    int getDate() const;
    string getItem() const;
    double getAmount() const;
    Type getOperationType() const;
};

#endif // OPERATION_H
