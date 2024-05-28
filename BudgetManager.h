#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include "OperationFile.h"
#include "DateMethods.h"
#include "CashMethods.h"

using namespace std;

class BudgetManager{
    OperationFile incomeFile;
    OperationFile expenseFile;
    const int LOGGED_USER_ID;
    vector <Operation> incomes;
    vector <Operation> expenses;
    ControlLastOperationIdFrom controlLastIncomeIdFrom;
    ControlLastOperationIdFrom controlLastExpenseIdFrom;

    Operation addOperationDetails(const Type &type);
    void showBalance(int startDate, int endDate);
    int getNewOperationId(const Type &type, ControlLastOperationIdFrom &controlLastOperationIdFrom);

public:
    BudgetManager(const string incomeFileName, const string expenseFileName, int loggedUserId): incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId){
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
        controlLastIncomeIdFrom = XMLFILE;
        controlLastExpenseIdFrom = XMLFILE;
    };

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};

#endif
