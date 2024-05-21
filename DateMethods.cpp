#include "DateMethods.h"

void DateMethods::calculateCurrentDate(map<string, int> & currentDate){}
int DateMethods::isYearLeap(int year){}

bool DateMethods::validateDate(const string &date){//TO DOO podzieliæ na oddzielne funkcje
    bool flag = true;
    regex pattern("\\d{4}-\\d{2}-\\d{2}");

    if (!regex_match(date, pattern)) {
        cout << "The correct date format is yyyy-mm-dd\n";
        return false;
    }

    //getCurrentDate();
    auto now = chrono::system_clock::now();
    auto nowTime = chrono::system_clock::to_time_t(now);
    tm *localTime = localtime(&nowTime);
    int currentYear = localTime->tm_year + 1900;

    //convertStringDateToInt
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);

    if (year < 2000 || year > currentYear) {
        cout << "Year should be between 2000 and current year.\n";
        flag = false;
    }

    if (month < 1 || month > 12) {
        cout << "Month should be between 1 and 12.\n";
        flag = false;
    }

    int daysInMonth;
    switch (month) {
        case 2:
            daysInMonth = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
    }

    if (day < 1 || day > daysInMonth) {
        cout << "Day should be between 1 and " << daysInMonth << " for the selected month.\n";
        flag = false;
    }

    if (flag == false){
        return false;
    }

    return true;
}

int DateMethods::convertStringDateToInt(const string &dateAsString){}
int DateMethods::convertDateToStringWithDasches(int dateAsInt){}
int DateMethods::getCurrentDate(){

}
int DateMethods::getCurrentMonthFirstDayDate(){}
int DateMethods::getPreviousMonthLastDayDate(){}
int DateMethods::getPreviousMonthFirstDayDate(){}
