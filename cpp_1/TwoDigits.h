#pragma once

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

using namespace std;

class TwoDigits
{
private: 
	char tensDigit, onesDigit;

public:
	// Constructor
	TwoDigits(int number);
	~TwoDigits() {};
	TwoDigits(char onesDigit='0', char tensDigit='0');
	int value();
	void update(int updatedNumber);
	void updateByChars(char onesDigit, char tensDigit);
	void printValue(bool withZeros=false);
};

