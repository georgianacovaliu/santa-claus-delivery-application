#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "scrisoare.h"
#include "Copil.h"
#include "KidsDataBase.h"
using namespace std;

void KidsDataBase::citeste_scrisori() {                 //Memoreaza in L datele copiilor din scrisori
    string line, ln, fn, age, city, dorinte, env;

    ifstream file("scrisori.csv");

    while (getline(file, line, '\n')) {
        stringstream s(line);
        getline(s, ln, ',');
        getline(s, fn, ',');
        getline(s, age, ',');
        getline(s, city, ',');
        getline(s, dorinte, ',');
        getline(s, env, '\n');

        Scrisoare scr(ln, fn, age, city, dorinte, env);    //Creeaza un obiect scrisoare
        Copil kid(scr);                                    //pe care i-l atribuie unui obiect copil

        L.push_back(kid);                                  //Copilul intra in vector
    }

    file.close();
}

void KidsDataBase::readElfList() {                    //Memoreaza in M datele copiilor de pe lista elfilor
    string line, ln, fn, age, city, stat;

    ifstream file("naughtyOrNot.csv");

    while (getline(file, line, '\n')) {
        stringstream s(line);
        getline(s, ln, ',');
        getline(s, fn, ',');
        getline(s, age, ',');
        getline(s, city, ',');
        getline(s, stat, '\n');

        Copil kid(ln, fn, age, city, stat);

        M.push_back(kid);                   //Copilul este introdus in vector
    }

    file.close();
}

void KidsDataBase::printKidNames() {                                 //Afiseaza numele copiilor care au trimis scrisori
    cout << "Copiii care au trimis scrisori sunt:\n"; 
    for (auto i = L.begin(); i != L.end(); ++i) {
        cout << (*i).letter.nume << " " << (*i).letter.prenume << endl;
    }
}

void KidsDataBase::printKidData() {                                 //Afiseaza informati cu privire la copiii care au trimis scrisori
    cout << "\nDatele fiecarui copil sunt:\n";
    cout << "Nume\tPrenume\tVarsta\tOras\t\tBuget\tWishlist\n";
    for (auto i = L.begin(); i != L.end(); ++i) {
        cout << (*i).letter.nume << "\t" << (*i).letter.prenume << "\t"
            << (*i).letter.varsta << "\t" << (*i).letter.oras << "\t"
            << (*i).buget << "\t" << (*i).letter.wishlist << endl;
    }
}