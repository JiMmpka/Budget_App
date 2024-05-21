#include "Operation.h"

void Operation::setId(int newId) { id = newId; }
void Operation::setUserId(int newUserId) { userId = newUserId; }
void Operation::setDate(const string &newDate) { date = newDate; }
void Operation::setItem(const string &newItem) { item = newItem; }
void Operation::setAmount(const string &newAmount) { amount = newAmount; }
void Operation::setOperationType(Type newOperationType) { operationType = newOperationType; }

int Operation::getId() const { return id; }
int Operation::getUserId() const { return userId; }
string Operation::getDate() const { return date; }
string Operation::getItem() const { return item; }
string Operation::getAmount() const { return amount; }
Type Operation::getOperationType() const { return operationType; }

