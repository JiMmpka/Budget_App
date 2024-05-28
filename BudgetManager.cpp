#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type){
    Operation operation;
    string date;
    string item;
    string amount;
    bool isOperationApplyToday;
    int intDate;
    double floatAmont;

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
            date = DateMethods::convertDateToStringWithDasches(DateMethods::getCurrentIntDate());
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

    do{
        cout << "Enter item name: ";
        item = Utils::readLine();
        operation.setItem(item);
    }
    while(Utils::validateInput(item));

    do{
        cout << "Enter amount: ";
        amount = Utils::readLine();
        amount = Utils::replaceCommaWithDot(amount);
        amount = CashMethods::changeAmountFormat(amount);

        if (CashMethods::validateAmount(amount)) {
            floatAmont = stod(amount);
            operation.setAmount(floatAmont);
            break;
        }
    }
    while(true);

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

void BudgetManager::showBalance(int startDate, int endDate){
    vector<Operation> filteredIncomes;
    vector<Operation> filteredExpenses;
    double totalIncome = 0.0;
    double totalExpense = 0.0;

    for (const Operation& income : incomes) {
        if (income.getDate() >= startDate && income.getDate() <= endDate) {
            filteredIncomes.push_back(income);
            totalIncome += income.getAmount();
        }
    }

    for (const Operation& expense : expenses) {
        if (expense.getDate() >= startDate && expense.getDate() <= endDate) {
            filteredExpenses.push_back(expense);
            totalExpense += expense.getAmount();
        }
    }

    auto sortByDate = [](const Operation& op1, const Operation& op2) {
        return op1.getDate() < op2.getDate();
    };

    sort(filteredIncomes.begin(), filteredIncomes.end(), sortByDate);
    sort(filteredExpenses.begin(), filteredExpenses.end(), sortByDate);

    cout << "Incomes:\n";
    for (const Operation& income : filteredIncomes) {
        cout << "Date: " << DateMethods::convertDateToStringWithDasches(income.getDate()) << ", Item: " << income.getItem() << ", Amount: " << fixed << setprecision(2) << showpoint << income.getAmount() << "\n";
    }

    cout << "\nExpenses:\n";
    for (const Operation& expense : filteredExpenses) {
        cout << "Date: " << DateMethods::convertDateToStringWithDasches(expense.getDate()) << ", Item: " << expense.getItem() << ", Amount: " << fixed << setprecision(2) << showpoint << expense.getAmount() << "\n";
    }

    cout << "\nSummary:\n";
    cout << "Total Income: " << fixed << setprecision(2) << showpoint << totalIncome << "\n";
    cout << "Total Expense: " << fixed << setprecision(2) << showpoint << totalExpense << "\n";
    cout << "Net Savings: " << fixed << setprecision(2) << showpoint << (totalIncome - totalExpense) << "\n";
    system("pause");
}

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

void BudgetManager::displayCurrentMonthBalance(){
    showBalance(DateMethods::getCurrentMonthFirstDayDate(), DateMethods::getCurrentIntDate());
}

void BudgetManager::displayPreviousMonthBalance(){
    showBalance(DateMethods::getPreviousMonthFirstDayDate(), DateMethods::getPreviousMonthLastDayDate());
}

void BudgetManager::displaySelectedPeriodBalance(){
    string startDate = "";
    string endDate = "";
    int intStartDate = 0;
    int intEndDate = 0;

    do{
        cout << "Enter start date: ";
        startDate = Utils::readLine();
    }
    while(!DateMethods::validateDate(startDate));

    do{
        cout << "Enter end date: ";
        endDate = Utils::readLine();
    }
    while(!DateMethods::validateDate(endDate));

    intStartDate = DateMethods::convertStringDateToInt(startDate);
    intEndDate = DateMethods::convertStringDateToInt(endDate);

    showBalance(intStartDate, intEndDate);
}

