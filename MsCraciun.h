#ifndef _MSCRACIUN_H_
#define _MSCRACIUN_H_
#include <iostream>
#include "Trol.h"
#include "Elf.h"
#include "Character.h"
#include "MosCraciun.h"

using namespace std;

class MsCraciun : public Character {
protected:
    double buget;

public:
    MsCraciun();
    ~MsCraciun();

    virtual void hello();
    void calculateBudget(Elf elv, Trol trl);   //Calculeaza bugetul extra
    void print();                      //Afiseaza bugetul
    void print(MosCraciun obj);  //Afiseaza traseul mosului
};

#endif