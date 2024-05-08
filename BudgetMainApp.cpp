#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn(){
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser(){
    userManager.registerUser();
}
void BudgetMainApp::loginUser(){
    userManager.loginUser();
}
void BudgetMainApp::changeLoggedInUserPassword(){
    userManager.changeLoggedInUserPassword();
}

void BudgetMainApp::logoutUser(){
    userManager.logoutUser();
}

void BudgetMainApp::addIncome(){}
void BudgetMainApp::addExpense(){}
void BudgetMainApp::displayCurrentMonthBalance(){}
void BudgetMainApp::displayPreviousMonthBalance(){}
void BudgetMainApp::displaySelectedPeriodBalance(){}
