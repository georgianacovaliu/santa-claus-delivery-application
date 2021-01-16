#include <iostream>
#include "Trol.h"
#include "Elf.h"
#include "MsCraciun.h"

using namespace std;

MsCraciun::MsCraciun() {
    buget = 0;
}

MsCraciun::~MsCraciun() {
    cout << "\nDoamna Craciun s-a dus la culcare!";
}

void MsCraciun::hello() {
    cout << "\n{DOAMNA CRACIUN}" << endl;
}

void MsCraciun::calculateBudget(Elf elv, Trol trl) {        //Calculeaza bugetul extra
    buget = elv.getAcadele() + 0.5 * trl.getCarbune();
}

void MsCraciun::print() {
    cout << "\nBugetul extra este de: " << buget << "$" << endl;      //Afiseaza bugetul exstra
}

void MsCraciun::print(MosCraciun obj) {                   //Afiseaza traseul mosului
    int i = 1;
    cout << "Destinatiile sunt: " << obj.traseu[0];
    while (i < V) {
        cout << ", " << obj.traseu[i];
        ++i;
    }
    cout << endl;
}