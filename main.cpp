#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MosCraciun.h"
#include "scrisoare.h"
#include "Copil.h"
#include "KidsDataBase.h"
#include "Gift.h"
#include "Elf.h"
#include "functions.h"
#include "Trol.h"
#include "MsCraciun.h"

using namespace std;

int main()
{
    cout << "Este o noua zi la Polul Nord...Iata, a sosit posta!\n\n";
    KidsDataBase obj;
    obj.citeste_scrisori();
    obj.readElfList();
    obj.printKidNames();
    obj.printKidData();

    Elf elv;
    elv.hello();
    cout << "\nVerifica lista de copii cuminti/obraznici si seteaza bugetul fiecarui copil\n";
    elv.setBuget(obj);
    obj.printKidData();
    cout <<"\nVerifica ce jucarii au in atelier\n";
    elv.lookWorkshop();
    elv.printWorkshop();
    cout << "\nStabilesc ce cadou va primi fiecare copil\n";
    elv.setCadou(obj);
    elv.printCadou(obj);

    Trol trl;
    trl.hello();
    trl.wrapGift(obj);
    cout << "\nStrecoara cate un carbune in cadoul fiecarui copil obraznic\n";
    trl.addCarbune(obj);
    elv.printCadou(obj);
    cout << "\nImpacheteaza fiecare cadou\n";
    trl.printWrap();

    MsCraciun dnaCraciun;
    dnaCraciun.hello();
    dnaCraciun.calculateBudget(elv, trl);
    dnaCraciun.print();

    MosCraciun mosul;
    mosul.hello();
    mosul.citesteKm();
    mosul.bestRoute();
    mosul.afisareTraseu();
    cout << "\nDeoarece nu vrea sa isi faca griji, Mosul impartaseste traseul sau cu Doamna Craciun\nInainte de pleceara, aceasta verifica drumul:\n\n";
    dnaCraciun.print(mosul);
    cout << "\nMosul a pornit la drum! Ho ho ho!\n";
}