#ifndef _SCRISOARE_H_
#define _SCRISOARE_H_
#include <iostream>

using namespace std;

class Scrisoare {
public:
    string nume;
    string prenume;
    string varsta;
    string oras;
    string wishlist;
    string plic;

    Scrisoare();

    Scrisoare(string lname, string fname, string age, string city, string wishlist, string env);

};

#endif