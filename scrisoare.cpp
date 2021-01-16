#include <iostream>
#include "scrisoare.h"

using namespace std;

Scrisoare::Scrisoare() {
    nume = "default";
    prenume = "default";
    varsta = "default";
    oras = "default";
    wishlist = "default";
    plic = "default";
}
Scrisoare::Scrisoare(string lname, string fname, string age, string city, string dorinte, string env) {
    nume = lname;
    prenume = fname;
    varsta = age;
    oras = city;
    wishlist = dorinte;
    plic = env;
}