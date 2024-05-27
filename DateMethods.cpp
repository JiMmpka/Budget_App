#include "DateMethods.h"

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

    splitStringDate(date, year, month, day);

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

string DateMethods::convertDateToStringWithDasches(int dateAsInt){
    ostringstream oss;
    oss << dateAsInt;
    string dateStr = oss.str();
    return dateStr.substr(0, 4) + "-" + dateStr.substr(4, 2) + "-" + dateStr.substr(6, 2);
}

tm DateMethods::getCurrentDate(){
    auto now = chrono::system_clock::now();
    time_t nowTime = chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &nowTime);

    return localTime;
}

int DateMethods::getCurrentIntDate(){
    tm currentDate;
    stringstream oss;
    int date = 0;

    currentDate = DateMethods::getCurrentDate();
    oss << (currentDate.tm_year + 1900) << ((currentDate.tm_mon + 1) < 10 ? "0" : "") << (currentDate.tm_mon + 1) << currentDate.tm_mday;
    oss >> date;

    return date;
}

void DateMethods::splitStringDate(const string &date, int &year, int &month, int &day){
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
}

void DateMethods::splitIntDate(const int &dateAsInt, int &year, int &month, int &day){
    year = dateAsInt / 10000;
    month = (dateAsInt / 100) % 100;
    day = dateAsInt % 100;
}

int DateMethods::mergeDate(const int &year, const int &month, const int &day){
    ostringstream oss;

    oss << year
    << setw(2) << setfill('0') << month
    << setw(2) << setfill('0') << day;

    return stoi(oss.str());
}

int DateMethods::getCurrentMonthFirstDayDate(){
    int intDate = 0;
    string stringDate = "";
    string firstDayOfTheMonth = "01";

    intDate = DateMethods::getCurrentIntDate();
    stringDate = Utils::convertIntToString(intDate);
    stringDate.resize(6);
    stringDate.append(firstDayOfTheMonth);

    return Utils::convertStringToInt(stringDate);
}


int DateMethods::getPreviousMonthFirstDayDate(){
    int intDate = 0;
    int firstDayOfTheMonth = 1;
    int year = 0;
    int month = 0;
    int day = 0;

    intDate = DateMethods::getCurrentIntDate();
    DateMethods::splitIntDate(intDate, year, month, day);
    day = firstDayOfTheMonth;

    if (month > 1) {
        month -= 1;
    } else {
        month = 12;
        year -= 1;
    }

    return mergeDate(year, month, day);
}

int DateMethods::getPreviousMonthLastDayDate(){
    int previousMonthFirstDayDate = 0;
    string stringDate = "";
    string firstDayOfTheMonth = "01";
    int year = 0;
    int month = 0;
    int day = 0;

    previousMonthFirstDayDate = getPreviousMonthFirstDayDate();
    splitIntDate(previousMonthFirstDayDate, year, month, day);
    day = numberOfDaysInMontch(year, month);

    return mergeDate(year, month, day);
}
