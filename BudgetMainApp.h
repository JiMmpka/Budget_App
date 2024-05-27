#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetMainApp{
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSE_FILE_NAMES;

public:
    BudgetMainApp(string userFileName, string incomeFileName, string expenseFileName)
    : userManager(userFileName), INCOMES_FILE_NAME(incomeFileName), EXPENSE_FILE_NAMES(expenseFileName){
        budgetManager = NULL;
    };

    ~BudgetMainApp(){
        delete budgetManager;
        budgetManager = NULL;
    }

    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void logoutUser();

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};

#endif
