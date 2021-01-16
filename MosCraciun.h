#ifndef _MOSCRACIUN_H_
#define _MOSCRACIUN_H_
#include "Character.h"
#define V 5

using namespace std;

class MosCraciun : public Character {
private:
    string traseu[V];  //Solutia ce va contine numele oraselor
    int sol[V];        //Solutia pe baza pozitiilor oraselor din matricea costurilor
    int graph[V][V];  //Matricea costurilor
    int s = 0;   //Nodul din care se pleaca

public:
    MosCraciun();

    virtual void hello();
    void citesteKm();  //Citeste din fisier matricea costurilor
    void bestRoute();    //Calculeaza drumul critic
    void afisareTraseu();

    friend class MsCraciun;
};

#endif