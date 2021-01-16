#ifndef _COPIL_H_
#define _COPIL_H_
#include "scrisoare.h"

using namespace std;

class Copil {
public:
    Scrisoare letter;
    int buget;
    string cadou;
    string status;

    Copil();

    Copil(Scrisoare scr);

    Copil(string ln, string fn, string age, string city, string stat);
};

#endif