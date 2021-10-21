#pragma once

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

class Fraction
{
private:
	// מונה
	int numerator;
	// מכנה
	int denominator;

public:
	
	Fraction(int denominator=1, int numerator=0);
	~Fraction() {};
	float value();
	
	void updateNumerator(int updatedNumerator);
	void updateDenominator(int updatedDenominator);
	void printValue(bool withEnter=true);
};

