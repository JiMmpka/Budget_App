#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type){
    Operation operation;
    int userId;
    string date;
    string item;
    string amount;

    operation.setId(getNewIncomeId());
    operation.setUserId(LOGGED_USER_ID);
    operation.setOperationType(type);

    do{
        cout << "Enter date: ";
        date = Utils::readLine();
        operation.setDate(date);
    }
    while(!DateMethods::validateDate(operation.getDate()));

    cout << "Enter item name: ";
    item = Utils::readLine();// validacja Utils::validateInput??
    operation.setItem(item);

    cout << "Enter amount: ";
    amount = Utils::readLine(); // validacja Utils::validateInput?? oraz przecinek na kropkê, oraz czy jest to liczba zmiennoprzecinkowa
    operation.setAmount(amount);

    return operation;
}

int BudgetManager::getNewIncomeId(){
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}

void BudgetManager::showBalance(int startDate, int endDate){}
double BudgetManager::calculateBalance(int startDate, int endDate, const Type &type){}

void BudgetManager::addIncome(){
    Operation operation = addOperationDetails(INCOME);

    incomes.push_back(operation);
    incomeFile.addOperationToFile(operation);

    cout << "\nIncome sucsessfully added\n\n";
    system("pause");
}

void BudgetManager::addExpense(){}
void BudgetManager::displayCurrentMonthBalance(){}
void BudgetManager::displayPreviousMonthBalance(){}
void BudgetManager::displaySelectedPeriodBalance(){}
