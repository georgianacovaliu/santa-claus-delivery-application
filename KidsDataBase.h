#ifndef _KIDSDATABASE_H_
#define _KIDSDATABASE_H_
#include <vector>
#include "Copil.h"

class KidsDataBase {
public:
    vector<Copil> L;        //Vector de copii ce au trimis scrisori
    vector<Copil> M;       //Vector de copii prezenti pe lista elfilor

    void citeste_scrisori();       //Memoreaza in L datele copiilor din scrisori
    void readElfList();           //Memoreaza in M datele copiilor de pe lista elfilor
    void printKidNames();         //Afiseaza numele copiilor care au trimis scrisori
    void printKidData();          //Afiseaza informati cu privire la copiii care au trimis scrisori

};

#endif