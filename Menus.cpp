#include "Menus.h"

void Menus::showTitle(string title){
    system("cls");
    cout << "    >>>  " << title << "  <<<\n";
}

void Menus::showHomeMenu(){
    cout << "---------------------------\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "9. Exit\n";
    cout << "---------------------------\n";
    cout << "Your choise: ";
}

void Menus::showMainMenu(){
    cout << "---------------------------\n";
    cout << "1. Add Income\n";
    cout << "2. Add Expense\n";
    cout << "3. Display Current Month Balance\n";
    cout << "4. Display Previous Month Balance\n";
    cout << "5. Display Selected Period Balance\n";
    cout << "---------------------------\n";
    cout << "6. Change Password\n";
    cout << "7. Logout\n";
    cout << "---------------------------" << endl;
    cout << "Your choise: ";
}

