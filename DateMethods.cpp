#include "DateMethods.h"

void DateMethods::calculateCurrentDate(map<string, int> & currentDate){}
bool DateMethods::isYearLeap(int year){
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int DateMethods::numberOfDaysInMontch(const int &year, const int &month){
    int daysInMonth;

    switch (month) {
    case 2:
        daysInMonth = isYearLeap(year) ? 29 : 28;
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
    return daysInMonth;
}

bool DateMethods::validateDate(const string &date){
    bool flag = true;
    regex pattern("\\d{4}-\\d{2}-\\d{2}");
    int daysInMonth;
    int currentYear;
    int year, month, day;
    tm currentDate;

    if (!regex_match(date, pattern)) {
        cout << "The correct date format is yyyy-mm-dd\n";
        return false;
    }

    currentDate = getCurrentDate();
    currentYear = currentDate.tm_year + 1900;

    splitTheDate(date, year, month, day);

    if (year < 2000 || year > currentYear) {
        cout << "Year should be between 2000 and current year.\n";
        flag = false;
    }

    if (month < 1 || month > 12) {
        cout << "Month should be between 1 and 12.\n";
        flag = false;
    }

    daysInMonth = numberOfDaysInMontch(year, month);

    if (day < 1 || day > daysInMonth) {
        cout << "Day should be between 1 and " << daysInMonth << " for the selected month.\n";
        flag = false;
    }

    if (flag == false){
        return false;
    }

    return true;
}

int DateMethods::convertStringDateToInt(const string &dateAsString){
    stringstream ss;
    for (char ch : dateAsString) {
        if (ch != '-') {
            ss << ch;
        }
    }

    int dateAsInt;
    ss >> dateAsInt;

    return dateAsInt;
}

int DateMethods::convertDateToStringWithDasches(int dateAsInt){}

tm DateMethods::getCurrentDate(){
    auto now = chrono::system_clock::now();
    time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &nowTime);
    return localTime;
}

void DateMethods::splitTheDate(const string &date, int &year, int &month, int &day){
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
}

int DateMethods::getCurrentMonthFirstDayDate(){}
int DateMethods::getPreviousMonthLastDayDate(){}
int DateMethods::getPreviousMonthFirstDayDate(){}
