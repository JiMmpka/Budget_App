#include "UserFile.h"

vector <User> UserFile::loadUsersFromFile(){ //TO DOO
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

User UserFile::getUsersData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami) //TO DOO
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

bool UserFile::appendUserToFile(User &user){
    CMarkup xml; //TO DOO - already created in File.h

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save("users.xml");

    return 0;
/*
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
    */
}


bool UserFile::changePasswordInFile(int userId, string &password){

}
