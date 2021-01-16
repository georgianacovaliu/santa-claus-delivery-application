#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Elf.h"
#include "Gift.h"
#include "KidsDataBase.h"
#include "Copil.h"
#include "functions.h"

using namespace std;

void Elf::hello() {
    cout << "\n{ELFII}" << endl;
}

Elf::Elf() {
    total_acadele = 0;
}

Elf::~Elf() {
    cout << "\nElfii s-au dus la culcare!\n";
}

int Elf::getAcadele() {
    return this->total_acadele;
}

void Elf::setAcadele(int x) {
    this->total_acadele = x;
}

void Elf::setBuget(KidsDataBase& kid) {
    int aux;
    for (auto i = kid.L.begin(); i != kid.L.end(); ++i) {      //Se parcurge vectorul de copii (care au trimis scrisori)
        try {
            aux = checkList(*i, kid);                          //Se verifica daca copilul apare pe lista si statusul sau
            if (aux) {
                if (aux == 1) {
                    (*i).status = "bun";
                    (*i).buget = 100;     //buget copil cuminte
                }
                else {
                    (*i).status = "rau";
                    (*i).buget = 10;     //buget copil obraznic
                }
            }
            else
                throw "\nOoops!";    //copilul nu apare pe lista elfilor
        }
        catch (const char* msg) {
            cerr << msg << endl;
            cout << "Se pare ca elfii nu si-au facut bine treaba... Unul din copiii care i-au scris mosului nu apare pe lista lor!\n"; //Acestuia i se aloca buget de copil cuminte
            (*i).buget = 100;
        }

    }
}

int Elf::checkList(Copil& child, KidsDataBase& kid) {
    for (auto j = kid.M.begin(); j != kid.M.end(); ++j) {             //Se parcurge vectorul de copii (lista elfilor);
        if (child.letter.nume == (*j).letter.nume) {                  //Daca datele din scrisoare se potrivesc cu datele de pe lista elfilor
            if (child.letter.prenume == (*j).letter.prenume) {        
                if (child.letter.varsta == (*j).letter.varsta) {
                    if (child.letter.oras == (*j).letter.oras) {
                        if ((*j).status == "good") {                 //se returneaza un int specific pentru status bun/rau
                            return 1;
                        }
                        else if ((*j).status == "bad")
                            return 2;
                    }
                }
            }
        }
    }
    return 0;  //daca nu exista copilul pe lista elfilor, se returneaza 0

}

void Elf::lookWorkshop() {
    string line, obj, price;                   //Se memoreaza cadourile din atelier.csv si preturile aferente in vectorul G 

    ifstream file("atelier.csv");

    while (getline(file, line, '\n')) {
        stringstream s(line);
        getline(s, obj, ',');
        getline(s, price, '\n');

        Gift cad(obj, stringToInt(price));

        G.push_back(cad);
    }

    file.close();
}

void Elf::printWorkshop() {
    cout << "\nIn atelier se gasesc urmatoarele obiecte:\n";    //Afiseaza cadourile si preturile aferente
    cout << "Item\tPret" << endl;
    for (auto i = G.begin(); i != G.end(); ++i) {
        cout << (*i).item << "\t" << (*i).pret << endl;
    }
}

void Elf::setCadou(KidsDataBase& kid) {
    string obj, acadele;

    for (auto i = kid.L.begin(); i != kid.L.end(); ++i) {
        int check_list = 0;     //Checker pentru a verifica daca a fost adaugat in punga vreun cadou de pe wishlist

        stringstream s((*i).letter.wishlist);

        while (getline(s, obj, ' ')) {
            for (auto j = G.begin(); j != G.end(); ++j) {
                if (obj == (*j).item && getMax<int>((*i).buget,(*j).pret) == (*i).buget){     //Verifica daca exista cadoul in atelier si daca bugetul alocat permite adaugarea acestuia in punga
                    (*i).cadou = (*i).cadou + obj + " ";               //Adauga cadoul in punga
                    (*i).buget = (*i).buget - (*j).pret;               //Actualizeaza bugetul
                    check_list = 1;
                }
            }
        }

        try {
            if (check_list == 1) {                                          //Daca s-au pus in punga cadouri de pe wishlist
                if ((*i).buget > 0) {                                       //se completeaza cu acadele din bugetul ramas
                    acadele = to_string((*i).buget);
                    total_acadele += (*i).buget;
                    (*i).cadou = (*i).cadou + "+ " + acadele + " de acadele";
                }
            }
            else
                throw check_list;
        }

        catch (int x) {                                                      //Daca NU s-au pus cadouri de pe wishlist
            if ((*i).status == "rau") {                                      //se verifica daca copilul a fost cuminte sau obraznic si i se atribuie cadou default
                (*i).cadou = "rechizite";   //cadou default de copil cuminte
            }
            else
                (*i).cadou = "bicicleta";   //cadou default de copil obraznic
        }
    }
}

void Elf::printCadou(KidsDataBase& kid) {                                                        //Afiseaza ce cadou va primi fiecare copil
    cout << "\nLista de cadouri:\n";
    for (auto i = kid.L.begin(); i != kid.L.end(); ++i) {
        cout << (*i).letter.nume << " " << (*i).letter.prenume << ": " << (*i).cadou << endl;
    }
}