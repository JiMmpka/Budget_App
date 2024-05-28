#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"

using namespace std;

int main(){
    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true){
        if (!budgetMainApp.isUserLoggedIn()){
            Menus::showTitle("HOME MENU");
            Menus::showHomeMenu();
            choice = Utils::getCharacter();

            switch (choice){
            case '1':
                budgetMainApp.loginUser();
                break;
            case '2':
                budgetMainApp.registerUser();
                break;
            case '9':
                cout << "\nSee you next time.\n";
                exit(0);
                break;
            default:
                cout <<"\nThere is no such option in menu. Try again.\n\n";
                system("pause");
                break;
            }
        }
        else{
            Menus::showTitle("MAIN MENU");
            Menus::showMainMenu();

            choice = Utils::getCharacter();;

            switch (choice){
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.displayCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.displayPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.displaySelectedPeriodBalance();
                break;
            case '6':
                budgetMainApp.changeLoggedInUserPassword();
                break;
            case '7':
                budgetMainApp.logoutUser();
                break;
            default:
                cout <<"\nThere is no such option in menu. Try again.\n\n";
                system("pause");
                break;
            }
        }
    }
    return 0;
}
