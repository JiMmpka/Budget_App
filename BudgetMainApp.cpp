#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}

void BudgetMainApp::loginUser(){
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    budgetManager = new BudgetManager(INCOMES_FILE_NAME, EXPENSE_FILE_NAMES, userManager.getLoggedUserId());
}

void BudgetMainApp::changeLoggedInUserPassword(){
    userManager.changeLoggedInUserPassword();
}

void BudgetMainApp::logoutUser(){
    userManager.logoutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void BudgetMainApp::addIncome(){}
void BudgetMainApp::addExpense(){}
void BudgetMainApp::displayCurrentMonthBalance(){}
void BudgetMainApp::displayPreviousMonthBalance(){}
void BudgetMainApp::displaySelectedPeriodBalance(){}
