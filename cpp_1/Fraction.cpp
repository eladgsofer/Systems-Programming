#include "Fraction.h"
#include <iostream>

/* Assignment: 1
Author: Elad Sofer, ID: 312124662
Author: Nimrod Sherrer, ID: 315932608
*/

using namespace std;

/**
 * @brief Construct a new Fraction:: Fraction object
 * 
 * @param numerator fraction's numerator. is set to 0 if given denominator equals 0.
 * @param denominator fraction's denominator. is set to 1 if given denominator equals 0.
 */
Fraction::Fraction(int numerator , int denominator)
{
	if (!denominator)
	{
		this->numerator = 0;
		this->denominator = 1;
	}
	else
	{
		this->denominator = denominator;
		this->numerator = numerator;
	}
}

/**
 * @brief converts fraction into float
 * 
 * @return float - object fraction number as float.
 */
float Fraction::value()
{
	return (float)this->numerator / (float)this->denominator;
}

/**
 * @brief switch bervious numerator with the new given value.
 * 
 * @param updatedNumerator new numerator.
 */
void Fraction::updateNumerator(int updatedNumerator)
{
	this->numerator = updatedNumerator;
}

/**
 * @brief switch bervious denominator with the new given value.
 * 
 * @param updatedDenominator new denominator.
 */
void Fraction::updateDenominator(int updatedDenominator)
{
	this->denominator = updatedDenominator;
}

/**
 * @brief prints value with an option to add '\n' at the end, overloading.
 * 
 * @param withEnter boolean: 1 add '\n', 0 without.
 */
void Fraction::printValue(bool withEnter)
{

	cout << this->numerator << "/" << this->denominator;

	if (withEnter)
		cout << "\n";
}
