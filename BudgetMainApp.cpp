#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}
void BudgetMainApp::loginUser(){}
void BudgetMainApp::changeLoggedInUserPassword(){}
void BudgetMainApp::logoutUser(){}

void BudgetMainApp::addIncome(){}
void BudgetMainApp::addExpense(){}
void BudgetMainApp::displayCurrentMonthBalance(){}
void BudgetMainApp::displayPreviousMonthBalance(){}
void BudgetMainApp::displaySelectedPeriodBalance(){}
