#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <map>
#include <regex>
#include <chrono>

#include "Utils.h"//TO DOO check if all includes are necessary


using namespace std;

class DateMethods{
    void calculateCurrentDate(map<string, int> & currentDate);//is that method necessary?
    int isYearLeap(int year);

public:
    static bool validateDate(const string &date); //TO DOO podzieliæ na oddzielne funkcje
    int convertStringDateToInt(const string &dateAsString);
    int convertDateToStringWithDasches(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
};

#endif
