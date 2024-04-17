#include "UserManager.h"

void UserManager::registerUser(){
    User user = enterNewUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << "\nAcount sucsessfully created\n\n";
    system("pause");
}

User UserManager::enterNewUserData(){
    User user;

    user.setId(getNewUserId());
    string login = "";
    string password = "";

    do{
        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();
        user.ustawLogin(login);
    }
    while (czyIstniejeLogin(user.pobierzLogin()) == true);

    cout << "Podaj password: ";
    password = MetodyPomocnicze::wczytajLinie();

    user.ustawHaslo(password);

    return user;
}

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().pobierzId() + 1;
}

bool UserManager::ifLoginExist(string login){
    for (int i = 0; i < users.size(); i++){
        if (users[i].pobierzLogin() == login){
            cout << endl << "Istnieje user o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loginUser(){
    User user;
    string login = "", password = "";
    vector <User>::iterator itr = users.begin();

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    while (itr != users.end()){
        if (itr -> pobierzLogin() == login){
            for (int iloscProb = 3; iloscProb > 0; iloscProb--){
                cout << "Podaj password. Pozostalo prob: " << iloscProb << ": ";
                password = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == password){
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne password." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changeLoggedInUserPassword(){
    string noweHaslo = "";
    cout << "Podaj nowe password: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        if (itr -> pobierzId() == idZalogowanegoUzytkownika){
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFile.zapiszWszystkichUzytkownikowDoPliku(users);
}

void UserManager::logoutUser(){
    loggedUserId = 0;
}

bool UserManager::isUserLoggedIn(){
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}
