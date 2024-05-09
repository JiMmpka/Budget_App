#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

struct Operation{
private:
    int id;
    int userId;
    string date;
    string item;
    string amount;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getId();
    int getUserId();
    string getdate();
    string getItem();
    string getAmount();
};
#endif
