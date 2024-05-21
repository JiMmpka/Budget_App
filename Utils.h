#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Utils{
public:
    static string convertIntToString(int number); //TODOO czy potrzebna u¿ywam stoi itp
    static int convertStringToInt(string strNumber); //TODOO czy potrzebna?
    static string readLine();
    static char getCharacter();
    static int readInt();
    static bool validateInput(string input);
    static string replaceCommaWithDot(string number);
};
#endif
