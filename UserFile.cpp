#include "UserFile.h"

bool UserFile::appendUserToFile(User &user){
    string liniaZDanymiUzytkownika = "";
    fstream plikTekstowy;
    plikTekstowy.open(getFileName().c_str(), ios::app);

    if (plikTekstowy.good() == true){
        //liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(user);

        if (isFileEmpty() == true){
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else{
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

vector <User> UserFile::loadUsersFromFile(){
    User user;
    vector <User> users;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    fstream plikTekstowy;
    plikTekstowy.open(getFileName().c_str(), ios::in);

    if (plikTekstowy.good() == true){
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami)){
            user = getUsersData(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            users.push_back(user);
        }
        plikTekstowy.close();
    }
    return users;
}

User UserFile::getUsersData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    User user;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++){
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|'){
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else{
            switch(numerPojedynczejDanejUzytkownika){
            case 1:
                user.setId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                user.setLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                user.setPassword(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return user;
}

bool UserFile::changePasswordInFile(int userId, string &password){

}
