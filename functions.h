#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_ 
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int stringToInt(string s);

template <typename T>
T getMax(T a, T b) {
    T result;
    result = (a > b) ? a : b;
    return (result);
}

#endif