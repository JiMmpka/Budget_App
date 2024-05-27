#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <regex>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

#include "Utils.h"//TO DOO check if all includes are necessary


using namespace std;

class DateMethods{
    static bool isYearLeap(int year);
    static void splitStringDate(const string &dateAsString, int &year, int &month, int &day);
    static void splitIntDate(const int &dateAsInt, int &year, int &month, int &day);
    static int mergeDate(const int &year, const int &month, const int &day);
    static int numberOfDaysInMontch(const int &year, const int &month);

public:
    static bool validateDate(const string &date);
    static int convertStringDateToInt(const string &dateAsString);
    static string convertDateToStringWithDasches(int dateAsInt);
    static tm getCurrentDate();
    static int getCurrentIntDate();
    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();
};

#endif
