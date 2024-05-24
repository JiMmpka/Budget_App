#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type){
    Operation operation;
    string date;
    string item;
    string amount;
    ostringstream oss;
    //string currentDateWithDasches;
    tm currentDate;
    bool isOperationApplyToday;
    int intDate;
    double floatAmont;
    size_t idx;

    if(type == INCOME)
        operation.setId(getNewOperationId(type, controlLastIncomeIdFrom));
    else if (type == EXPENSE)
        operation.setId(getNewOperationId(type, controlLastExpenseIdFrom));

    operation.setUserId(LOGGED_USER_ID);
    operation.setOperationType(type);

    cout << "Does the operation apply to today? Type ""Y"" for yes or ""N"" for no: ";
    isOperationApplyToday = ( "Y" == Utils::capitalizeFirstLetter(Utils::getCharacter())) ? true : false;

    do{
        if (isOperationApplyToday){
            currentDate = DateMethods::getCurrentDate();
            oss << (currentDate.tm_year + 1900) << "-" << ((currentDate.tm_mon + 1) < 10 ? "0" : "") << (currentDate.tm_mon + 1) << "-" << currentDate.tm_mday;
            date = oss.str();
            cout << "\nDate: "<< date << "\n";
        }
        else{
            cout << "Enter date: ";
            date = Utils::readLine();
        }
            intDate = DateMethods::convertStringDateToInt(date);
            operation.setDate(intDate);
    }
    while(!DateMethods::validateDate(date));

    cout << "Enter item name: ";
    item = Utils::readLine();
    operation.setItem(item);

    do{
        cout << "Enter amount: ";
        amount = Utils::readLine();
        amount = Utils::replaceCommaWithDot(amount);
        amount = CashMethods::changeAmountFormat(amount);
        floatAmont = stod(amount);
        operation.setAmount(floatAmont);
    }
    while(!CashMethods::validateAmount(amount));

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
