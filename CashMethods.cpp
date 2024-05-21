#include "CashMethods.h"

regex CashMethods::intPattern("^-?\\d+$");
regex CashMethods::floatPattern("^-?\\d+\\.\\d+$");

bool CashMethods::validateAmount(string amount){
    if (!regex_match(amount, intPattern) && !regex_match(amount, floatPattern)){
        cout << "Wrong amount format. Type floats or integers.\n";
        return false;
    }
    return true;
}

string CashMethods::changeAmountFormat(string amount){
    if (regex_match(amount, intPattern)) {
        amount += ".00";
    } else if (regex_match(amount, floatPattern)) {
        size_t dotPosition = amount.find('.');
        if (amount.size() - dotPosition == 2) {
            amount += "0";
        }
    }
    return amount;
}
