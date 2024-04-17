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
    static int readInt();
    static bool validateInput(string input);
};
#endif
