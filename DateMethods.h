#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <map>

#include "Utils.h"//TO DOO check if all includes are necessary


using namespace std;

class DateMethods{
    void calculateCurrentDate(map<string, int> & currentDate);
    int isYearLeap(int year);

public:
    bool validateDate(string &date);
    int convertStringDateToInt(const string &dateAsString);
    int convertDateToStringWithDasches(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
};

#endif
