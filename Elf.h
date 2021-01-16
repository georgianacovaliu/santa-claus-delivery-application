#ifndef _ELF_H_
#define _ELF_H_ 
#include <vector>
#include "Gift.h"
#include "KidsDataBase.h"
#include "Copil.h"
#include "Character.h"

using namespace std;

class Elf : public Character {
private:
    int total_acadele;

public:
    Elf();
    ~Elf();
    vector<Gift> G;

    int getAcadele();    //Metode de get si set pentru total_acadele
    void setAcadele(int x);

    virtual void hello();
    void setBuget(KidsDataBase&);  //Seteaza bugetul pentru fiecare copil
    int checkList(Copil&, KidsDataBase&);  //Verifica daca copilul care a trimis scrisoarea exista pe lista copii cuminti/obraznici si returneaza un int specific 
                                           //1 pentru cuminte, 2 pentru obraznic, 0 pentru nu exista pe lista elfilor
    void lookWorkshop();   //Memoreaza cadourile din atelier.csv si preturile aferente in vectorul G 
    void printWorkshop(); //Afiseaza cadourile si preturile aferente  (din vectorul G)
    void setCadou(KidsDataBase&);  //Seteaza cadoul pentru fiecare copil
    void printCadou(KidsDataBase& kid);  //Afiseaza ce cadou va primi fiecare copil
};

#endif