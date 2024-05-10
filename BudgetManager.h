#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>//TO DOO check if all includes are necessary
#include <fstream>
#include <sstream>
#include <string>

#include "OperationFile.h"
#include "Utils.h"
#include "Operation.h"
#include "Type.h"

using namespace std;

class BudgetManager{
    OperationFile incomeFile;
    OperationFile expenseFile;
    const int LOGGED_USER_ID;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager(const string incomeFileName, const string expenseFileName, int loggedUserId): incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId){};

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};

#endif
