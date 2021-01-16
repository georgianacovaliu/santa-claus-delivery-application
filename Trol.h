#ifndef _TROL_H_
#define _TROL_H_
#include "KidsDataBase.h"
#include "Character.h"

using namespace std;

class Trol : public Character {
private:
    int pinkWrap;
    int blueWrap;
    int carbune;

public:
    Trol();
    ~Trol();
    int getPinkWrap();         //Setters si getters pentru atribute
    int getBlueWrap();
    int getCarbune();
    void setPinkWrap(int x);
    void setBlueWrap(int x);
    void setCarbune(int x);

    virtual void hello();
    void wrapGift(KidsDataBase&);    //Numara ambalajele de fete si de baieti
    void addCarbune(KidsDataBase&);  //Adauga un carbune la atributul cadou al fiecarui copil cu status "rau" din vector
    void printWrap();                //Afiseaza ambalajele folosite
};

#endif