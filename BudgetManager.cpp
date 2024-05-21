#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type){
    Operation operation;
    string date;
    string item;
    string amount;

    if(type == INCOME)
        operation.setId(getNewOperationId(type, controlLastIncomeIdFrom));
    else if (type == EXPENSE)
        operation.setId(getNewOperationId(type, controlLastExpenseIdFrom));

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

int BudgetManager::getNewOperationId(const Type &type, ControlLastOperationIdFrom &controlLastOperationIdFrom){
    if (type == INCOME){
        if (controlLastOperationIdFrom == XMLFILE){
            controlLastOperationIdFrom = VECTOR;
            return incomeFile.getLastOperationId() + 1;
        }
        else {
            if (incomes.empty())
                return 1;
            else
                return incomes.back().getId() + 1;
        }
    }
    else if(type == EXPENSE){
        if (controlLastOperationIdFrom == XMLFILE){
            controlLastOperationIdFrom = VECTOR;
            return expenseFile.getLastOperationId() + 1;
        }
        else {
            if (expenses.empty())
                return 1;
            else
                return expenses.back().getId() + 1;
        }
    }
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

void BudgetManager::addExpense(){
    Operation operation = addOperationDetails(EXPENSE);

    expenses.push_back(operation);
    expenseFile.addOperationToFile(operation);

    cout << "\nExpense sucsessfully added\n\n";
    system("pause");
}

void BudgetManager::displayCurrentMonthBalance(){}
void BudgetManager::displayPreviousMonthBalance(){}
void BudgetManager::displaySelectedPeriodBalance(){}
