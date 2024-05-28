#include "Utils.h"

string Utils::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int Utils::convertStringToInt(string strNumber){
    int number;
    istringstream iss(strNumber);
    iss >> number;

    return number;
}

string Utils::readLine(){
    string input = "";
    getline(cin, input);
    return input;
}

char Utils::getCharacter(){
    string input = "";
    char sign  = {0};

    while (true){
        getline(cin, input);

        if (input.length() == 1){
            sign = input[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return sign;
}

bool Utils::validateInput(string input){
    if(input == ""){
        cout << "\nThe entrance should have at least 1 sign.\n";
        return true;
    }

    return false;
}

string Utils::replaceCommaWithDot(string number) {
    replace(number.begin(), number.end(), ',', '.');
    return number;
}

string Utils::capitalizeFirstLetter(char ch) {
    string text(1, ch);
    text[0] = toupper(text[0]);
    return text;
}
