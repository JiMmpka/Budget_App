#include "Operation.h"

void Operation::setId(int newId) { id = newId; }
void Operation::setUserId(int newUserId) { userId = newUserId; }
void Operation::setDate(const int &newDate) { date = newDate; }
void Operation::setItem(const string &newItem) { item = newItem; }
void Operation::setAmount(const double &newAmount) { amount = newAmount; }
void Operation::setOperationType(Type newOperationType) { operationType = newOperationType; }

int Operation::getId() const { return id; }
int Operation::getUserId() const { return userId; }
int Operation::getDate() const { return date; }
string Operation::getItem() const { return item; }
double Operation::getAmount() const { return amount; }
Type Operation::getOperationType() const { return operationType; }

