#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Utils{
public:
    static string convertIntToString(int number);
    static int convertStringToInt(string strNumber);
    static string readLine();
    static char getCharacter();
    static bool validateInput(string input);
    static string replaceCommaWithDot(string number);
    static string capitalizeFirstLetter(char character);
};
#endif
