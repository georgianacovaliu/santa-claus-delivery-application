#include <iostream>
#include "Gift.h"

using namespace std;

Gift::Gift() {
    item = "unknown";
    pret = 0;
}

Gift::Gift(string obj, int price) {
    item = obj;
    pret = price;
}