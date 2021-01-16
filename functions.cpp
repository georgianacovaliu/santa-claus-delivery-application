#include "functions.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int stringToInt(string s) {
    stringstream geek(s);
    int x = 0;
    geek >> x;

    return x;
}
