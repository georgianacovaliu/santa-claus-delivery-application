#include <iostream>
#include "Copil.h"

using namespace std;

Copil::Copil() {
    buget = 0;
    cadou = "";
    status = "unknown";
}

Copil::Copil(Scrisoare scr) {
    buget = 0;
    cadou = "";
    letter = scr;
    status = "unknown";
}

Copil::Copil(string ln, string fn, string age, string city, string stat) {
    buget = 0;
    cadou = "";
    status = stat;
    letter.nume = ln;
    letter.prenume = fn;
    letter.varsta = age;
    letter.oras = city;
    letter.plic = "unknown";
    letter.wishlist = "unknown";
}