#ifndef _CHARACTER_H_
#define _CHARACTER_H_ 
#include <iostream>

using namespace std;

class Character {
public:
	Character() {
		cout << "\n\nIntra in scena...";
	}
	virtual void hello() = 0;
};

#endif