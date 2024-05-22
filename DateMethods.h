#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <map>
#include <regex>
#include <chrono>
#include <ctime>

#include "Utils.h"//TO DOO check if all includes are necessary


using namespace std;

class DateMethods{
    void calculateCurrentDate(map<string, int> & currentDate);//is that method necessary?
    static bool isYearLeap(int year);
    static void splitTheDate(const string &date, int &year, int &month, int &day);
    static int numberOfDaysInMontch(const int &year, const int &month);

public:
    static bool validateDate(const string &date); //TO DOO podzieliæ na oddzielne funkcje
    static int convertStringDateToInt(const string &dateAsString);
    int convertDateToStringWithDasches(int dateAsInt);
    static tm getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
};

#endif
