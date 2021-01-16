#include "Trol.h"
#include "KidsDataBase.h"
#include <iostream>

using namespace std;

Trol::Trol() {
    pinkWrap = 0;
    blueWrap = 0;
    carbune = 0;
}

Trol::~Trol() {
    cout << "\nTrolii s-au dus la culcare!";
}

void Trol::hello() {
    cout << "\n{TROLII}" << endl;
}

int Trol::getBlueWrap() {
    return this->blueWrap;
}

int Trol::getPinkWrap() {
    return this->pinkWrap;
}

int Trol::getCarbune() {
    return this->carbune;
}

void Trol::setBlueWrap(int x) {
    this->blueWrap = x;
}

void Trol::setPinkWrap(int x) {
    this->pinkWrap = x;
}

void Trol::setCarbune(int x) {
    this->carbune = x;
}

void Trol::wrapGift(KidsDataBase& kid) {
    for (auto i = kid.L.begin(); i != kid.L.end(); ++i) {      //Se parcurge vectorul copii; se verifica culoarea plicului; se incrementeaza ambalajele de fete si de baieti
        if ((*i).letter.plic == "roz") {
            pinkWrap++;
        }
        else if ((*i).letter.plic == "albastru") {
            blueWrap++;
        }
    }
}

void Trol::addCarbune(KidsDataBase& kid) {
    for (auto i = kid.L.begin(); i != kid.L.end(); ++i) {      //Se parcurge vectorul copii si se adauga un carbune daca statusul copilului e "rau"
        if ((*i).status == "rau") {
            (*i).cadou = (*i).cadou + " + " + "carbune";
            ++carbune;
        }
    }
}

void Trol::printWrap() {
    cout << "\nTrolii au folosit " << pinkWrap << " ambalaje de fete si " << blueWrap << " ambalaje de baieti." << endl;        //Afiseaza ambalajele folosite
}