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

void BudgetMainApp::addIncome(){
    budgetManager->addIncome();
}

void BudgetMainApp::addExpense(){
    budgetManager->addExpense();
}
void BudgetMainApp::displayCurrentMonthBalance(){
    budgetManager->displayCurrentMonthBalance();
}

void BudgetMainApp::displayPreviousMonthBalance(){
    budgetManager->displayPreviousMonthBalance();
}

void BudgetMainApp::displaySelectedPeriodBalance(){
    budgetManager->displaySelectedPeriodBalance();
}
