#ifndef CASHMETHODS_H
#define CASHMETHODS_H

#include <iostream>
#include <regex>

using namespace std;

class CashMethods{
    static regex intPattern;
    static regex floatPattern;

public:
    static string changeAmountFormat(string amount);
    static bool validateAmount(string amount);
};

#endif
