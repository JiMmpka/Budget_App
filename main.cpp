#include <iostream>
#include "BudgetMainApp.h"
#include "Menus.h"
#include "Utils.h"

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
                //budgetMainApp.displayCurrentMonthBalance();
                break;
            case '4':
                //budgetMainApp.displayPreviousMonthBalance();
                break;
            case '5':
                //budgetMainApp.displaySelectedPeriodBalance();
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



/*
// Funkcja do wyci¹gania daty i kwoty z pliku XML
void extractDateAndAmountFromXML(const char* filename) {
    CMarkup xml;
    if (xml.Load(filename)) {
        if (xml.FindElem("transaction")) {
            xml.IntoElem();
            xml.FindElem("date");
            string date = xml.GetData();
            xml.FindElem("amount");
            string amount = xml.GetData();
            cout << "Date: " << date << ", Amount: " << amount << endl;
        }
    }
}

// Funkcja obliczaj¹ca ile dni ma obecny miesi¹c
void daysInCurrentMonth(){
    auto now = chrono::system_clock::now();
    auto current_month = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&current_month);
    int days_in_month = now_tm->tm_mday; // Dzienne wartoœci 1-31 wskazuj¹ na ostatni dzieñ miesi¹ca
    cout << "Days in current month: " << days_in_month << endl;
}

// Funkcja obliczaj¹ca datê poprzedniego miesi¹ca
tm previousMonth() {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    timeinfo->tm_mon -= 1;
    mktime(timeinfo);
    return *timeinfo;
}

// Funkcja porównuj¹ca daty
bool compareDates(const string& date1Str, const string& date2Str) {
    tm date1 = {};
    tm date2 = {};

    // Parsowanie daty 1
    istringstream iss1(date1Str);
    iss1 >> get_time(&date1, "%Y-%m-%d");
//    if (iss1.fail()) {
 //       cerr << "Error parsing date 1: " << date1Str << endl;
 //       return false;
 //   }

    // Parsowanie daty 2
    istringstream iss2(date2Str);
    iss2 >> get_time(&date2, "%Y-%m-%d");
 //   if (iss2.fail()) {
//        cerr << "Error parsing date 2: " << date2Str << endl;
//        return false;
 //   }

    // Porównywanie dat
    return (mktime(&date1) == mktime(&date2));
}

string getCurrentDate() {
    // Pobieranie bie¿¹cej daty i czasu
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);

    // Konwersja bie¿¹cej daty do lokalnego czasu
    tm* now_tm = localtime(&now_time);

    // Formatowanie daty do postaci "yyyy-mm-dd"
    ostringstream oss;
    oss << put_time(now_tm, "%Y-%m-%d");
    return oss.str();
}

void isLeapYear() {
    auto now = chrono::system_clock::now();
    auto current_year = chrono::system_clock::to_time_t(now);
    tm* now_tm = localtime(&current_year);
    int year = now_tm->tm_year + 1900; // Rok od 1900
    bool is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (is_leap_year) {
        cout << year << " is a leap year" << endl;
    } else {
        cout << year << " is not a leap year" << endl;
    }
}

int main() {

    // 1. Wyci¹ganie daty i kwoty z pliku XML
    extractDateAndAmountFromXML("example.xml");

    // 2. Obliczanie ile ma dni obecny miesi¹c
    daysInCurrentMonth();

    // 3. Obliczanie daty poprzedniego miesi¹ca
    tm prevMonth = previousMonth();
    cout << "Previous month: " << prevMonth.tm_year + 1900 << "-" << prevMonth.tm_mon + 1 << "-" << prevMonth.tm_mday << endl;

    // 4. Porównywanie dat
    string date1 = "2024-03-28";
    string date2 = "2024-03-28";

    if (compareDates(date1, date2)) {
        cout << "Dates are equal" << endl;
    } else {
        cout << "Dates are not equal" << endl;
    }


    // 5. sprawdzenie czy bie¿acy rok jest prestêpny
    isLeapYear();

    // 6. bie¿¹ca data
    string current_date = getCurrentDate();
    cout << "Current date: " << current_date << endl;

    return 0;
}
*/
