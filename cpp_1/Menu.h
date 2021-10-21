#pragma once
#include "TwoDigits.h"

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

class Menu
{
private:
	char bufferCleanr[2];
	bool recieveTwoDigitsByChars(TwoDigits& twoDigitsByChars);
	bool recieveTwoDigitsByInt(TwoDigits& twoDigitsByInt);
public:
	Menu();
	~Menu() {};
	void mainMenu();
	void twoDigitsMenu();
	void fractionMenu();
	void stringMenu();
};

